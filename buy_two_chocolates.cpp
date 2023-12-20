class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini1 = INT_MAX, mini2 = INT_MAX, ignore = -1;

        for(int i=0; i < prices.size(); i++) {
            if(prices[i] < mini1) {
                mini1 = prices[i];
                ignore = i;
            }
        }
        for(int i=0; i < prices.size(); i++) {
            if(i == ignore) continue;
            mini2 = min(mini2, prices[i]);
        }

        int finalSum = money - mini1 - mini2;
        return finalSum < 0 ? money : finalSum;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)