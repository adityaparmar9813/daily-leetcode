class Solution {
   public:
	vector<vector<int>> dp;

	int solve(const string& s, int index, bool bSeen) {
		if (index == s.size()) {
			return 0;
		}
		if (dp[index][bSeen] != -1) {
			return dp[index][bSeen];
		}

		char ch = s[index];

		int remove = 1 + solve(s, index + 1, bSeen);
		int notRemove;

		if (bSeen) {
			notRemove = ch == 'a' ? 1e9 : solve(s, index + 1, bSeen);
		} else {
			notRemove = ch == 'b' ? solve(s, index + 1, true)
			                      : solve(s, index + 1, false);
		}

		return dp[index][bSeen] = min(remove, notRemove);
	}

	int minimumDeletions(string s) {
		dp.resize(s.size(), vector<int>(2, -1));
		return solve(s, 0, false);
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)