class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int n = grid.size();

        for(int i=1; i < n-1; i++) {           
            for(int j=1; j < n-1; j++) {
                for(int r=i-1; r <= i+1; r++) {
                    for( int c=j-1; c <= j+1; c++) {
                        grid[i-1][j-1] = max(grid[i-1][j-1], grid[r][c]);
                    }
                }
            }

            grid[i-1].resize(n-2);
        }
        grid.resize(n-2);
        return grid;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)
