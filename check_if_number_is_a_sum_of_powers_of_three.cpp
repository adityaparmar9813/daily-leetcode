class Solution {
   public:
	unordered_map<string, bool> dp;

	bool solve(long long curr, int n, string memo) {
		if (curr == n) {
			return true;
		}
		if (curr > n) {
			return false;
		}
		if (dp.find(memo) != dp.end()) {
			return dp[memo];
		}

		for (int i = 0; i <= 15; i++) {
			char ch = 'a' + i;

			if (memo.find(ch) != string::npos) {
				continue;
			}

			string newMemo = memo + ch;
			sort(newMemo.begin(), newMemo.end());

			if (solve(curr + pow(3, i), n, newMemo)) {
				return dp[memo] = true;
			}
		}

		return dp[memo] = false;
	}

	bool checkPowersOfThree(int n) { return solve(0, n, ""); }
};

// Time Complexity: O(log(n))
// Space Complexity: O(log(n))