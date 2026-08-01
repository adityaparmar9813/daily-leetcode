class Solution {
   public:
	int solve(vector<int>& nums, int i, int j, bool turn,
	          vector<vector<vector<int>>>& dp) {
		if (i > j) {
			return 0;
		}

		if (dp[i][j][turn] != -1) {
			return dp[i][j][turn];
		}

		if (turn) {
			int left = nums[i] + solve(nums, i + 1, j, false, dp);
			int right = nums[j] + solve(nums, i, j - 1, false, dp);
			return dp[i][j][turn] = max(left, right);
		}

		int left = solve(nums, i + 1, j, true, dp);
		int right = solve(nums, i, j - 1, true, dp);
		return dp[i][j][turn] = min(left, right);
	}

	bool predictTheWinner(vector<int>& nums) {
		int totalSum = accumulate(nums.begin(), nums.end(), 0);
		int n = nums.size();
		vector<vector<vector<int>>> dp(
		    n, vector<vector<int>>(n, vector<int>(2, -1)));

		int score1 = solve(nums, 0, n - 1, true, dp);
		return score1 * 2 >= totalSum;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)