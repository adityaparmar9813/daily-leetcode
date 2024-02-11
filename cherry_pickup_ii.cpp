class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>> &grid, int index, int j1, int j2){
        int m = grid[0].size();

        if(j1<0 || j1>=m || j2<0 || j2>=m){
            return -1e9;
        }

        if(index == grid.size()-1){
            if(j1 == j2) return grid[index][j1];
            return grid[index][j1] + grid[index][j2];
        }
        if(dp[index][j1][j2] != -1) return dp[index][j1][j2];

        int maxi =0;

        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int val=0;

                if(j1 == j2) val = grid[index][j1] + solve(grid, index+1, j1+i, j2+j);
                else val = grid[index][j1] + grid[index][j2] + solve(grid, index+1, j1+i, j2+j);
                
                maxi = max(maxi, val);
            }
        }
        return dp[index][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        dp.resize(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return solve(grid, 0, 0, grid[0].size()-1);
    }
};

// Time Complexity : O(n^3)
// Space Complexity : O(n^3)