class Solution {
  public:
	int solve(vector<vector<int>> &grid, int i, int j,
			  vector<vector<int>> &dp) {
		if (j == grid[0].size() - 1) {
			dp[i][j] = 1;
		}

		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		int ans = 0;
		if (grid[i][j + 1] > grid[i][j]) {
			ans = solve(grid, i, j + 1, dp);
		}
		if (i != 0 && grid[i - 1][j + 1] > grid[i][j]) {
			ans = max(ans, solve(grid, i - 1, j + 1, dp));
		}
		if (i != grid.size() - 1 && grid[i + 1][j + 1] > grid[i][j]) {
			ans = max(ans, solve(grid, i + 1, j + 1, dp));
		}
		return dp[i][j] = 1 + ans;
	}

	int maxMoves(vector<vector<int>> &grid) {
		vector<vector<int>> dp(1000, vector<int>(1000, -1));
		int ans = 0;

		for (int i = 0; i < grid.size(); i++) {
			ans = max(ans, solve(grid, i, 0, dp));
		}
		return ans - 1;
	}
};

// Time Complexity : O(n * m)
// Space Complexity : O(n * m)