class Solution {
  public:
	int dp[101][101];
	int helper(int l, int r, string &str) {
		if (l > r) {
			return 0;
		}
		if (dp[l][r] != -1) {
			return dp[l][r];
		}

		int ans = 1 + helper(l + 1, r, str);

		for (int i = l + 2; i <= r; i++) {
			if (str[i] == str[l]) {
				ans = min(ans, helper(i, r, str) + helper(l + 1, i - 1, str));
			}
		}
		return dp[l][r] = ans;
	}

	int strangePrinter(string s) {
		memset(dp, -1, sizeof(dp));
		string str;
		int i = 0;

		while (i < s.size()) {
			char ch = s[i];

			while (i < s.size() && ch == s[i]) {
				i++;
			}
			str.push_back(ch);
		}
		return helper(0, str.size() - 1, str);
	}
};

// Time Complexity : O(n ^ 3)
// Space Complexity : O(n ^ 2)