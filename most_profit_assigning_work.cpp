class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size(), ans = 0;
        vector<pair<int, int>> job;

        for (int i = 0; i < n; i++) {
            job.push_back({difficulty[i], profit[i]});
        }
        sort(job.begin(), job.end());

        vector<int> maxProfit(n);
        maxProfit[0] = job[0].second;
        for (int i = 1; i < n; i++) {
            maxProfit[i] = max(maxProfit[i-1], job[i].second);
        }
        
        for (int i = 0; i < worker.size(); i++) {
            int l = 0, r = n;

            while (l < r-1) {
                int mid = l + (r-l) / 2;
                
                if (job[mid].first <= worker[i]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }

            if (job[r-1].first <= worker[i]) {
                ans += maxProfit[r-1];
            }
        }
        return ans;
    }
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)
