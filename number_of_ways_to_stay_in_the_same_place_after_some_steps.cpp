class Solution {
public:
    const int MOD = 1e9+7;
    vector<vector<int>> dp;
    int solve(int pos, int steps, int arrLen) {
        if(steps == 0 && pos == 0) return 1;
        if(steps == 0) return 0;
        if(dp[pos][steps] != -1) return dp[pos][steps];

        int stay = 0, left = 0, right = 0;

        if(pos != 0) left = solve(pos-1, steps-1, arrLen);
        stay = solve(pos, steps-1, arrLen);
        if(pos != arrLen-1) right = solve(pos+1, steps-1, arrLen);

        return dp[pos][steps] = ((left + stay) % MOD + right) % MOD;
    }

    int numWays(int steps, int arrLen) {
        // Will not pass without this optimization
        arrLen = min(steps/2 + 1, arrLen);
        dp.resize(arrLen, vector<int>(steps+1, -1));

        return solve(0, steps, arrLen);
    }
};

// Time Complexity = O(steps * arrLen)
// Space Complexity = O(steps * arrLen)