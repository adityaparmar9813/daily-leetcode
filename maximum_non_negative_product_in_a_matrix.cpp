class Solution {
   private:
	using ll = long long;

	int mod = 1e9 + 7;
	vector<int> drow = {1, 0};
	vector<int> dcol = {0, 1};

	vector<vector<pair<ll, ll>>> dp;

	pair<ll, ll> memo(int r, int c, vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		if (r == n - 1 && c == m - 1) {
			return {grid[r][c], grid[r][c]};
		}

		if (dp[r][c] != make_pair(-1e9, -1e9)) {
			return dp[r][c];
		}

		ll currVal = grid[r][c];
		ll maxi = -1e9;
		ll mini = 1e9;

		for (int i = 0; i < 2; i++) {
			int newr = r + drow[i];
			int newc = c + dcol[i];

			if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
				auto nextData = memo(newr, newc, grid);

				maxi = max({maxi, nextData.first * currVal,
				            nextData.second * currVal});

				mini = min({mini, nextData.first * currVal,
				            nextData.second * currVal});
			}
		}

		dp[r][c] = {maxi, mini};
		return dp[r][c];
	}

   public:
	int maxProductPath(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		dp.assign(n, vector<pair<ll, ll>>(m, {-1e9, -1e9}));

		pair<ll, ll> result = memo(0, 0, grid);

		if (result.first < 0) {
			return -1;
		}

		return result.first % mod;
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n ^ 2)