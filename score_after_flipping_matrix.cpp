class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 1) {
                continue;
            }

            for (int j = 0; j < grid[i].size(); j++) {
                grid[i][j] = grid[i][j] == 1 ? 0 : 1;
            }
        }

        for (int j = 1; j < grid[0].size(); j++) {
            int oneCount = 0;

            for (int i = 0; i < grid.size(); i++) {
                oneCount += (grid[i][j] == 1);
            }
            
            if (2 * oneCount >= grid.size()) {
                continue;
            }

            for (int i = 0; i < grid.size(); i++) {
                grid[i][j] = grid[i][j] == 1 ? 0 : 1;
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            int mult = 1;

            for (int j = grid[i].size()-1; j >= 0; j--) {
                ans += grid[i][j] * mult;
                mult = mult * 2;
            }
        }
        return ans;
    }
};

// Time Complexity : O(n*m)
// Space Complexity : O(1)
