class Solution {
  public:
	const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	int minimumTime(vector<vector<int>> &grid) {
		int r = grid.size(), c = grid[0].size();

		if (grid[0][1] > 1 && grid[1][0] > 1)
			return -1;

		vector<vector<int>> dp(r, vector<int>(c, -1));
		dp[0][0] = 0;

		queue<pair<int, int>> bfs;
		bfs.push({0, 0});

		while (!bfs.empty()) {
			auto [curRow, curCol] = bfs.front();
			bfs.pop();

			for (const auto &[dr, dc] : dirs) {
				int nr = curRow + dr;
				int nc = curCol + dc;

				if (nr < 0 || nc < 0 || nr >= r || nc >= c)
					continue;

				int next = dp[curRow][curCol] + 1;

				if (next < grid[nr][nc]) {
					int diff = grid[nr][nc] - next;
					if (diff % 2 != 0)
						diff++;
					next += diff;
				}

				if (next >= grid[nr][nc] &&
					(dp[nr][nc] == -1 || next < dp[nr][nc])) {
					dp[nr][nc] = next;
					bfs.push({nr, nc});
				}
			}
		}

		return dp[r - 1][c - 1];
	}
};

// Time Complexity: O(r * c * log(r * c))
// Space Complexity: O(r * c)