class Solution {
   public:
	const int MOD = 1e9 + 7;
	vector<vector<int>> dp;

	int solve(int n, int x, int curr) {
		if (n == 0) {
			return 1;
		}

		long long power = 1;

		for (int i = 0; i < x; i++) {
			power *= curr;

			if (power > n) {
				return 0;
			}
		}

		if (n - power < 0) {
			return 0;
		}
		if (dp[n][curr] != -1) {
			return dp[n][curr];
		}

		int take = solve(n - power, x, curr + 1);
		int notTake = solve(n, x, curr + 1);

		return dp[n][curr] = (take + notTake) % MOD;
	}

	int numberOfWays(int n, int x) {
		dp.assign(n + 1, vector<int>(n + 1, -1));
		return solve(n, x, 1);
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)