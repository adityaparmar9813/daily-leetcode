class Solution {
   public:
	int countSubmatrices(vector<vector<int>>& grid, int k) {
		int m = grid.size(), n = grid[0].size(), ans = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 1; j < n; j++) {
				grid[i][j] += grid[i][j - 1];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				grid[j][i] += grid[j - 1][i];
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				ans += (grid[i][j] <= k);
			}
		}

		return ans;
	}
};

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)