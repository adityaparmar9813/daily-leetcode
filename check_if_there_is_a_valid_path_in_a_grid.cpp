class Solution {
   public:
	vector<vector<vector<int>>> dirs = {{},
	                                    {{0, -1}, {0, 1}},
	                                    {{-1, 0}, {1, 0}},
	                                    {{0, -1}, {1, 0}},
	                                    {{0, 1}, {1, 0}},
	                                    {{0, -1}, {-1, 0}},
	                                    {{-1, 0}, {0, 1}}};

	bool dfs(int x, int y, vector<vector<bool>>& vis,
	         vector<vector<int>>& grid) {
		vis[x][y] = true;
		int m = grid.size(), n = grid[0].size();

		if (x == m - 1 && y == n - 1) {
			return true;
		}

		for (vector<int> d : dirs[grid[x][y]]) {
			int nx = x + d[0];
			int ny = y + d[1];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;

			vector<vector<int>> nextDir = dirs[grid[nx][ny]];
			bool connected = false;

			for (vector<int> nd : nextDir) {
				if (nx + nd[0] == x && ny + nd[1] == y) {
					connected = true;
					break;
				}
			}

			if (!connected) continue;

			if (dfs(nx, ny, vis, grid)) return true;
		}

		return false;
	}

	bool hasValidPath(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<bool>> vis(m, vector<bool>(n));
		return dfs(0, 0, vis, grid);
	}
};

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)