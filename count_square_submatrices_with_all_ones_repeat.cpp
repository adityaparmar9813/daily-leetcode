class Solution {
   public:
	int dp[300][300];

	int solve(int i, int j, vector<vector<int>>& matrix) {
		if (i < 0 || j < 0 || matrix[i][j] == 0) {
			return 0;
		}
		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		return dp[i][j] = 1 + min({solve(i - 1, j, matrix),
		                           solve(i - 1, j - 1, matrix),
		                           solve(i, j - 1, matrix)});
	}

	int countSquares(vector<vector<int>>& matrix) {
		const int r = matrix.size(), c = matrix[0].size();
		memset(dp, -1, sizeof(dp));
		int count = 0;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				count += solve(i, j, matrix);
			}
		}

		return count;
	}
};

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)