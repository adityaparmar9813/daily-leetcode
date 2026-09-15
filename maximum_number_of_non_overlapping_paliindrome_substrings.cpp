class Solution {
   public:
	int maxPalindromes(string s, int k) {
		int n = s.size();
		vector<vector<bool>> isPal(n, vector<bool>(n, false));

		for (int i = 0; i < n; ++i) {
			isPal[i][i] = true;
		}

		for (int i = 0; i + 1 < n; ++i) {
			if (s[i] == s[i + 1]) {
				isPal[i][i + 1] = true;
			}
		}

		for (int len = 3; len <= n; ++len) {
			for (int i = 0; i + len - 1 < n; ++i) {
				int j = i + len - 1;

				if (s[i] == s[j] && isPal[i + 1][j - 1]) {
					isPal[i][j] = true;
				}
			}
		}

		vector<int> dp(n + 1, 0);

		for (int i = 1; i <= n; ++i) {
			dp[i] = dp[i - 1];

			for (int j = 0; j <= i - k; ++j) {
				if (isPal[j][i - 1]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		return dp[n];
	}
};

// Time Complexity: O(n ^ 3)
// Space Complexity: O(n ^ 2)