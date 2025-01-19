class Solution {
   public:
	int trapRainWater(vector<vector<int>>& height) {
		int n = height.size(), m = height[0].size();
		priority_queue<pair<int, pair<int, int>>,
		               vector<pair<int, pair<int, int>>>,
		               greater<pair<int, pair<int, int>>>>
		    pq;
		vector<vector<int>> vis(n, vector<int>(m));

		for (int i = 0; i < n; i++) {
			vis[i][0] = 1;
			vis[i][m - 1] = 1;
			pq.push({height[i][0], {i, 0}});
			pq.push({height[i][m - 1], {i, m - 1}});
		}

		for (int i = 0; i < m; i++) {
			vis[0][i] = 1;
			vis[n - 1][i] = 1;
			pq.push({height[0][i], {0, i}});
			pq.push({height[n - 1][i], {n - 1, i}});
		}

		int ans = 0;

		while (!pq.empty()) {
			int h = pq.top().first;
			int r = pq.top().second.first;
			int c = pq.top().second.second;
			pq.pop();

			vector<int> dr = {-1, 0, 1, 0};
			vector<int> dc = {0, -1, 0, 1};

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
					ans += max(0, h - height[nr][nc]);
					pq.push({max(h, height[nr][nc]), {nr, nc}});
					vis[nr][nc] = 1;
				}
			}
		}
		return ans;
	}
};

// Time Complexity: O(n * m * log(n * m))
// Space Complexity: O(n * m)