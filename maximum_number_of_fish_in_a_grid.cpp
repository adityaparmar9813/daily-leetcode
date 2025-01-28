class Solution {
   public:
	vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

	int dfs(int i, int j, vector<vector<int>>& grid,
	        vector<vector<bool>>& visited) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
		    grid[i][j] == 0 || visited[i][j]) {
			return 0;
		}

		visited[i][j] = true;
		int ans = grid[i][j];

		for (const auto& [x, y] : dir) {
			ans += dfs(i + x, j + y, grid, visited);
		}

		return ans;
	}

	int findMaxFish(vector<vector<int>>& grid) {
		int ans = 0;
		vector<vector<bool>> visited(grid.size(),
		                             vector<bool>(grid[0].size(), false));

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (!visited[i][j]) {
					ans = max(ans, dfs(i, j, grid, visited));
				}
			}
		}

		return ans;
	}
};

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)