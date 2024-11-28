class Solution {
  public:
	int minimumObstacles(vector<vector<int>> &grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> result(m, vector<int>(n, INT_MAX));
		vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

		priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
		pq.push({0, 0, 0});

		while (!pq.empty()) {
			auto vec = pq.top();
			pq.pop();

			int ans = vec[0], i = vec[1], j = vec[2];

			if (i == m - 1 && j == n - 1) {
				return ans;
			}

			for (auto &dir : direction) {
				int a = i + dir[0], b = j + dir[1];

				if (a < 0 || b < 0 || a >= m || b >= n) {
					continue;
				}

				if (ans + grid[a][b] < result[a][b]) {
					result[a][b] = ans + grid[a][b];
					pq.push({ans + grid[a][b], a, b});
				}
			}
		}

		return -1;
	}
};