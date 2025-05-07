class Solution {
   public:
	int minTimeToReach(vector<vector<int>>& moveTime) {
		int m = moveTime.size(), n = moveTime[0].size();
		vector<vector<long long>> dist(m, vector<long long>(n, LLONG_MAX));
		vector<vector<bool>> vis(m, vector<bool>(n, false));
		vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		priority_queue<tuple<long long, int, int>,
		               vector<tuple<long long, int, int>>, greater<>>
		    pq;
		dist[0][0] = 0;
		pq.emplace(0, 0, 0);

		while (!pq.empty()) {
			auto [t, x, y] = pq.top();
			pq.pop();

			if (vis[x][y]) {
				continue;
			}
			vis[x][y] = true;

			if (x == m - 1 && y == n - 1) {
				return t;
			}

			for (auto& d : dir) {
				int nx = x + d.first, ny = y + d.second;

				if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
					long long nt = max(t, (long long)moveTime[nx][ny]) + 1;

					if (nt < dist[nx][ny]) {
						dist[nx][ny] = nt;
						pq.emplace(nt, nx, ny);
					}
				}
			}
		}

		return -1;
	}
};

// Time Complexity: O(m * n * log(m * n))
// Space Complexity: O(m * n)