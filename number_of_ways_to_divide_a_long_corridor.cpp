class Solution {
public:
    const int MOD = (int)1e9 + 7;
    long long dp[100001][3];

    long long getAns(string& a, int i, int k) {
        if(i >= a.size()) return k == 2;
        
        if(dp[i][k] != -1) return dp[i][k];   
        if(k == 2) {
            if(a[i] == 'P') 
                return dp[i][k] = (getAns(a, i+1, 0) % MOD + getAns(a, i+1, k) % MOD) % MOD;

            else return dp[i][k] = getAns(a, i + 1, 1) % MOD;
        }
        else return dp[i][k] = getAns(a, i+1, k+(a[i] == 'S')) % MOD;
    }
    int numberOfWays(string corridor) {
        memset(dp, -1, sizeof(dp));
        return getAns(corridor, 0, 0); 
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)