class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int helper(int n, int m, int k, int maxi) {
        if(k < 0) return 0;
        if(n == 0) return !k;
        if(dp[n][k][maxi] != -1) return dp[n][k][maxi];

        int count = 0;
        for(int i = 1 ; i <= m ; i++){
            if(i > maxi) count = (count + helper(n-1, m, k-1, i)) % mod;
            else count = (count + helper(n-1, m, k, maxi)) % mod;
        }
        return dp[n][k][maxi] = count;
    }

    int numOfArrays(int n, int m, int k) {
        dp.resize(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, -1)));
        return helper(n, m, k, 0);
    }
};

// Time Complexity : O(n^3)
// Space Complexity : O(n^3)