class Solution {
   public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		int m = isWater.size(), n = isWater[0].size();
		vector<vector<int>> ans(m, vector<int>(n, -1));
		queue<pair<int, int>> q;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (isWater[i][j]) {
					q.emplace(i, j);
					ans[i][j] = 0;
				}
			}
		}

		vector<int> dirs = {0, 1, 0, -1, 0};

		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dirs[k], ny = y + dirs[k + 1];

				if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
				    ans[nx][ny] == -1) {
					ans[nx][ny] = ans[x][y] + 1;
					q.emplace(nx, ny);
				}
			}
		}

		return ans;
	}
};

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)