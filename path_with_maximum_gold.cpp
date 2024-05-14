class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size() || i < 0 || j >= grid[i].size() || j < 0 || grid[i][j] == 0) {
            return 0;
        }

        int curr = grid[i][j];
        grid[i][j] = 0;

        int left = dfs(grid, i, j-1);
        int right = dfs(grid, i, j+1);
        int up = dfs(grid, i-1, j);
        int down = dfs(grid, i+1, j);

        grid[i][j] = curr;
        return curr + max(left, max(right, max(up, down)));
    } 
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i=0; i < grid.size(); i++) {
            for(int j=0; j < grid[i].size(); j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};

// Time Complexity : O(4^n)
// Space Complexity : O(n)
