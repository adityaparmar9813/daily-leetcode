class Solution {
   public:
	int maxDifference(string s, int k) {
		int n = s.length();
		vector<vector<int>> prefix(5, vector<int>(n, 0));

		for (int i = 0; i < n; i++) {
			prefix[s[i] - '0'][i]++;
		}

		for (int i = 0; i <= 4; i++) {
			for (int j = 1; j < n; j++) {
				prefix[i][j] += prefix[i][j - 1];
			}
		}
		int ans = INT_MIN;

		for (int a = 0; a <= 4; a++) {
			for (int b = 0; b <= 4; b++) {
				if (a != b) {
					int i = 0;
					vector<vector<int>> dp(2, vector<int>(2, 1e8));
					int freq_a = 0;
					int freq_b = 0;
					int prev_a = 0;
					int prev_b = 0;

					for (int j = k - 1; j < n; j++) {
						freq_a = prefix[a][j];
						freq_b = prefix[b][j];

						while (j - i + 1 >= k && freq_b - prev_b >= 2) {
							dp[prev_a & 1][prev_b & 1] = min(
							    dp[prev_a & 1][prev_b & 1], prev_a - prev_b);
							prev_a = prefix[a][i];
							prev_b = prefix[b][i];
							i++;
						}

						ans = max(ans, freq_a - freq_b -
						                   dp[1 - (freq_a & 1)][freq_b & 1]);
					}
				}
			}
		}

		return ans;
	}
};

// Time Complexity: O(n * 25)
// Space Complexity: O(n * 5)