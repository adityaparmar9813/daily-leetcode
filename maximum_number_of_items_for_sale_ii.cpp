#define ll long long

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int maxFactor = 0, cheapestPrice = INT_MAX;

        for(int i = 0; i < items.size(); i++) {
            maxFactor = max(maxFactor, items[i][0]);
            cheapestPrice = min(cheapestPrice, items[i][1]);
        }

        vector<int> freqFactors(maxFactor + 1);
        
        for(int i = 0; i < n; i++) {
            freqFactors[items[i][0]]++;
        }

        for(int i = 1; i <= maxFactor; i++) {
            if(freqFactors[i]) {
                for(int j = 2 * i; j <= maxFactor; j += i) {
                    freqFactors[i] += freqFactors[j];
                }
            }
        }

        map<ll, ll> costCount;

        for(int i = 0; i < n; i++) {
            int factor = items[i][0];
            int cost = items[i][1];

            int count = freqFactors[factor] - 1;

            if(count > 0 && cost <= cheapestPrice * 2) {
                costCount[cost] += count;
            }
        }

        int res = 0;

        for(auto it: costCount) {
            int cost = it.first;
            ll count = it.second;
            ll possibleCount = min<ll>(count, budget / cost);

            res += (possibleCount * 2);

            budget -= (possibleCount * cost);
        }

        res += (budget / cheapestPrice);


        return res;

    }
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)