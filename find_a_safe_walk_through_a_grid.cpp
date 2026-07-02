class Solution {
   public:
	vector<vector<int>> dp;

	bool solve(vector<vector<int>>& grid, int i, int j, int health) {
		int m = grid.size(), n = grid[0].size();

		if (i < 0 || i == m || j < 0 || j == n) {
			return false;
		}

		health = grid[i][j] == 1 ? health - 1 : health;

		if (health == 0 || dp[i][j] >= health) {
			return false;
		}

		dp[i][j] = health;

		if (i == m - 1 && j == n - 1) {
			return true;
		}

		return solve(grid, i - 1, j, health) || solve(grid, i, j + 1, health) ||
		       solve(grid, i + 1, j, health) || solve(grid, i, j - 1, health);
	}

	bool findSafeWalk(vector<vector<int>>& grid, int health) {
		dp.resize(grid.size(), vector<int>(grid[0].size(), -1));
		return solve(grid, 0, 0, health);
	}
};

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)