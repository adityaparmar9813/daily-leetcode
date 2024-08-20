class Solution {
  public:
	int dp[101][301][2];
	int solve(int index, int m, vector<int> &piles, int turn) {
		int n = piles.size();
		if (index >= n) {
			return 0;
		}
		if (dp[index][m][turn] != -1) {
			return dp[index][m][turn];
		}

		int sum = 0, ans = 0;

		if (turn) {
			for (int j = index; j < n && j < index + 2 * m; j++) {
				sum += piles[j];
				ans = max(ans,
						  sum + solve(j + 1, max(m, j - index + 1), piles, 0));
			}
		} else {
			ans = 1e9;
			for (int j = index; j < n && j < index + 2 * m; j++) {
				ans = min(ans, solve(j + 1, max(m, j - index + 1), piles, 1));
			}
		}
		return dp[index][m][turn] = ans;
	}

	int stoneGameII(vector<int> &piles) {
		memset(dp, -1, sizeof(dp));
		return solve(0, 1, piles, 1);
	}
};

// Time Complexity : O(n ^ 3)
// Space Complexity : O(n ^ 2)