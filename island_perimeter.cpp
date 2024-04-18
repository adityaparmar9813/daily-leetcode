class Solution {
public:
    int blockPerimeter(vector<vector<int>>& grid, int i, int j) {
        int perimeter = 0;

        if(i == 0 || grid[i-1][j] == 0) {
            perimeter++;
        } 
        if(i == grid.size()-1 || grid[i+1][j] == 0) {
            perimeter++;
        } 
        if(j == 0 || grid[i][j-1] == 0) {
            perimeter++;
        } 
        if(j == grid[0].size() - 1 || grid[i][j+1] == 0) {
            perimeter++;
        }
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i=0; i < grid.size(); i++) {
            for(int j=0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0) {
                    continue;
                }
                ans += blockPerimeter(grid, i, j);
            }
        }
        return ans;
    }
};


// Time Complexity : O(n*m)
// Space Complexity : O(1)
