class Solution {
   public:
	int minCost(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
		deque<pair<int, int>> dq;

		vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

		dq.push_front({0, 0});
		dist[0][0] = 0;

		while (!dq.empty()) {
			auto [x, y] = dq.front();
			dq.pop_front();
			int currDir = grid[x][y] - 1;

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir], ny = y + dy[dir];

				if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
					continue;
				}

				int cost = dist[x][y] + (dir == currDir ? 0 : 1);

				if (cost < dist[nx][ny]) {
					dist[nx][ny] = cost;

					if (dir == currDir) {
						dq.push_front({nx, ny});
					} else {
						dq.push_back({nx, ny});
					}
				}
			}
		}

		return dist[m - 1][n - 1];
	}
};

// Time Complexity : O(n * m * log(n * m))
// Space Complexity : O(n * m)