class Solution {
   public:
	vector<vector<int>> dp;
	const int MOD = 1e9 + 7;

	int solve(int n, int k) {
		if (k >= n || k == 0) {
			return 0;
		}
		if (k == 1) {
			return 1ll * n * (n - 1) / 2 % MOD;
		}
		if (n == 2) {
			return 0;
		}
		if (dp[n][k] != -1) {
			return dp[n][k];
		}

		long long ans = solve(n - 1, k);

		for (int i = 1; i < n; i++) {
			ans = (ans + solve(n - i, k - 1)) % MOD;
		}

		return dp[n][k] = (int)ans;
	}

	int numberOfSets(int n, int k) {
		dp.assign(n + 1, vector<int>(k + 1, -1));
		return solve(n, k);
	}
};

// Time Complexity : O(n * k)
// Space Complexity : O(n * k)