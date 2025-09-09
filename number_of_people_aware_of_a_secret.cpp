class Solution {
   public:
	int peopleAwareOfSecret(int n, int delay, int forget) {
		constexpr int MOD = 1e9 + 7;
		vector<int> dp(n);
		dp[0] = 1;
		long share = 0, result = 0;

		for (int i = 1; i < n; ++i) {
			if (i - delay >= 0) {
				share = (share + dp[i - delay]) % MOD;
			}
			if (i - forget >= 0) {
				share = (share - dp[i - forget] + MOD) % MOD;
			}
			dp[i] = share;
		}

		for (int i = n - forget; i < n; ++i) {
			result = (result + dp[i]) % MOD;
		}

		return result;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)