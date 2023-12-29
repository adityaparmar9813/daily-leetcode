class Solution {
    public:
    int dfs(int last, int d, int n, vector<int> &nums, vector<vector<int>> &dp) {
        if(d == 0) {
            int mx = 0;
            for(int j=last+1; j<n; j++) mx = max(mx, nums[j]);
            return mx;
        }
        if(last != -1 && dp[last][d] != -1) return dp[last][d];
        
        int mx = 0, ans = 1e9;
        for(int j=last+1; j<n-1; j++) {
            mx = max(mx, nums[j]);
            ans = min(ans, mx + dfs(j, d-1, n, nums, dp));
        }

        if(last != -1) dp[last][d] = ans;
        return ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;

        vector<vector<int>> dp(n, vector<int>(d, -1));
        return dfs(-1, d-1, n, jobDifficulty, dp);
    }
};

// Time Complexity: O(n^2 * d)
// Space Complexity: O(n * d)