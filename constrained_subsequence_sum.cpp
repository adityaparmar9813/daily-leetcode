class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        priority_queue<pair<int, int>> pq;
        int ans = INT_MIN;
        dp[0] = nums[0];
        
        ans = max(ans, dp[0]);
        pq.push({dp[0], 0});

        for(int i = 1; i < nums.size(); i++) {
            pair<int, int> t = pq.top();
            while(t.second < i - k) {
                pq.pop();
                t = pq.top();
            }

            dp[i] = max(0, t.first) + nums[i];
            ans = max(ans, dp[i]);
            pq.push({dp[i], i});
        }
        return ans;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)