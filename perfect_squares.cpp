class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);

        for(int i=1; i*i <= n; i++) {
            dp[i*i] = 1;
        }

        for(int i=1; i <= n; i++) {
            if(dp[i] == 1) continue;
            int root = sqrt(i), mini = INT_MAX;

            for(int j=1; j<=root; j++){
                mini = min(mini, dp[j*j] + dp[i - j*j]);
            }
            dp[i] = mini;
        }
        return dp[n];
    }
};

// Time Complexity : O(n^3/2)
// Space Complexity : O(n)