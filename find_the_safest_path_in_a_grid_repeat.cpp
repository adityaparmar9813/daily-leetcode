class Solution {
   public:
	int m, n;
	vector<vector<int>> safety;
	vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	bool dfs(int i, int j, int mid, vector<vector<int>>& memo) {
		if (i < 0 || i >= m || j < 0 || j >= n) return false;
		if (safety[i][j] < mid) return false;
		if (i == m - 1 && j == n - 1) return true;
		if (memo[i][j] != -1) return memo[i][j];
		memo[i][j] = 0;
		bool result = false;
		for (auto& [dx, dy] : dirs) {
			if (dfs(i + dx, j + dy, mid, memo)) {
				result = true;
				break;
			}
		}
		memo[i][j] = result;
		return result;
	}
	bool feasible(int mid) {
		vector<vector<int>> memo(m, vector<int>(n, -1));
		return dfs(0, 0, mid, memo);
	}
	int maximumSafenessFactor(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		int INF = m + n;
		safety.assign(m, vector<int>(n, INF));
		queue<pair<int, int>> q;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] == 1) {
					safety[i][j] = 0;
					q.push({i, j});
				}
		while (!q.empty()) {
			auto [i, j] = q.front();
			q.pop();
			for (auto& [dx, dy] : dirs) {
				int ni = i + dx, nj = j + dy;
				if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
				    safety[ni][nj] == INF) {
					safety[ni][nj] = safety[i][j] + 1;
					q.push({ni, nj});
				}
			}
		}
		int lo = 0, hi = min(safety[0][0], safety[m - 1][n - 1]);
		int ans = 0;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (feasible(mid)) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		return ans;
	}
};

// Time Complexity : O(m * n  * log(m * n))
// Space Complexity : O(m * n)