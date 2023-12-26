class Solution {
public:
    const int MOD = 1e9+7;
    vector<vector<int>> dp;
    int solve(int n, int k, int target) {
        if(n == 0 && target == 0) return 1;
        if(n == 0 || target <= 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];

        long long ans = 0;
        for(int i=1; i <= k; i++) {
            ans = (ans + solve(n-1, k, target-i)) % MOD;
        }
        return dp[n][target] = ans % MOD;
    }

    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1, vector<int>(target+1, -1));
        if (target > n * k) return 0;
        return solve(n, k, target);
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)