class Solution {
public:
    int dp[5][4][5001];
    int MOD = 1e9+7;
    int solve(int k,int i,int j) {
        if(i<0 || j<0 || i>=4 || j>=3 || (i==3 && (j==0 || j==2))) return 0;
        if(k==1) return 1;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        int moves = solve(k-1,i+1,j-2) % MOD;
        moves = (moves + solve(k-1, i+1, j+2)) % MOD;
        moves = (moves + solve(k-1, i+2, j-1)) % MOD;
        moves = (moves + solve(k-1, i+2, j+1)) % MOD;
        moves = (moves + solve(k-1, i-1, j-2)) % MOD;
        moves = (moves + solve(k-1, i-1, j+2)) % MOD;
        moves = (moves + solve(k-1, i-2, j-1)) % MOD;
        moves = (moves + solve(k-1, i-2, j+1)) % MOD;
            
        return dp[i][j][k] = moves; 
    }
    int knightDialer(int n) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<4;i++) for(int j=0;j<3;j++) ans=(ans + solve(n, i, j)) % MOD;
        return ans;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)