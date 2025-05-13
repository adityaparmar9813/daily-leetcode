class Solution {
   public:
	const int MOD = 1e9 + 7;
	vector<vector<int>> dp;

	int solve(int ch, int t) {
		if (t == 0) {
			return 1;
		}
		if (dp[ch][t] != -1) {
			return dp[ch][t];
		}

		if (ch == 25) {
			return dp[ch][t] = (solve(0, t - 1) + solve(1, t - 1)) % MOD;
		}
		return dp[ch][t] = solve(ch + 1, t - 1);
	}

	int lengthAfterTransformations(string s, int t) {
		dp.resize(26, vector<int>(t + 1, -1));
		long long ans = 0;

		for (char ch : s) {
			ans = (ans + solve(ch - 'a', t)) % MOD;
		}
		return ans;
	}
};

// Time Complexity: O(n + t)
// Space Complexity: O(n + t)