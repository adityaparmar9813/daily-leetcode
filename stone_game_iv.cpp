class Solution {
   public:
	vector<vector<int>> dp;
	int solve(int n, bool turn) {
		if (n == 0) {
			return !turn;
		}
		if (n == 1) {
			return turn;
		}
		if (dp[n][turn] != -1) {
			return dp[n][turn];
		}

		bool res;

		if (turn) {
			res = false;

			for (int i = 1; i * i <= n; i++) {
				res = res || solve(n - i * i, !turn);
			}
		} else {
			res = true;

			for (int i = 1; i * i <= n; i++) {
				res = res && solve(n - i * i, !turn);
			}
		}
		return dp[n][turn] = res;
	}
	bool winnerSquareGame(int n) {
		dp.resize(n + 1, vector<int>(2, -1));
		return solve(n, true);
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)