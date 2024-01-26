class Solution {
public:
    int dp[51][51][51];
    long mod = 1e9+7;
    
    int dfs(int m,int n,int mvs,int row,int col){
        if(row >= m || col >= n || row < 0 || col < 0)
            return 1;
        if(!mvs)
            return 0;
        if(dp[row][col][mvs] != -1)
            return dp[row][col][mvs];
        
        long res = 0;
        
        res += dfs(m,n,mvs-1,row-1,col);
        res += dfs(m,n,mvs-1,row,col+1);
        res += dfs(m,n,mvs-1,row+1,col);
        res += dfs(m,n,mvs-1,row,col-1);
        
        return dp[row][col][mvs] = res % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        
        return dfs(m,n,maxMove,startRow,startColumn);
    }
};

// Time Complexity: O(m*n*p)
// Space Complexity: O(m*n*p)
