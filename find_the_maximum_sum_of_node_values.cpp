class Solution {
public:
    long long solve(int i, vector<int>& values, vector<vector<long long>> &dp, int n, int count, int k) {
        if (i == n) {
            return count == 0 ? 0 : -1e9;
        } if (dp[i][count] != -1) {
            return dp[i][count];
        }

        long long take = (values[i] ^ k) + solve(i+1, values, dp, n, !count, k);
        long long notTake = values[i] + solve(i+1, values, dp, n, count, k);

        return dp[i][count] = max(take, notTake);
    }

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, nums, dp, n, 0, k);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
