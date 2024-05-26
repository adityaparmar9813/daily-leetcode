class Solution {
public:
    const int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;

    int solve(int curr, int lateCount, bool absent, int n) {
        if (curr == n) {
            return 1;
        } if (dp[curr][lateCount][absent] != -1) {
            return dp[curr][lateCount][absent];
        }

        int ans = solve(curr+1, 0, absent, n);
        if (lateCount < 2) {
            ans = (ans + solve(curr+1, lateCount+1, absent, n)) % MOD;
        }
        if (!absent) {
            ans = (ans + solve(curr+1, 0, true, n)) % MOD;
        }
        return dp[curr][lateCount][absent] = ans;
    }
    
    int checkRecord(int n) {
        dp.resize(n+1, vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(0, 0, false, n);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
