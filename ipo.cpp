class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> store;

        for(int i = 0; i < capital.size(); i++) {
            store.push_back({capital[i], i});
        }
        sort(store.begin(), store.end());

        int ans = w, i = 0;
        priority_queue<int> pq;

        while(k--) {
            while(i < capital.size() and store[i].first <= ans) {
                pq.push(profits[store[i++].second]);
            }
            if(pq.empty()) {
                break;
            }
            ans += pq.top(); pq.pop();
        }
        return ans;
    }
};

// Time Complexity: O(n*log(n) + k*log(n))
// Space Complexity: O(n)
