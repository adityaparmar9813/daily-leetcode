class Solution {
   public:
	int maxDistance(vector<int>& colors) {
		int n = colors.size();
		vector<int> dp(n, -1);
		return solve(0, n - 1, colors, dp);
	}

	int solve(int i, int j, vector<int>& colors, vector<int>& dp) {
		if (j == i) return 0;

		if (dp[i] != -1) return dp[i];

		if (colors[i] != colors[j]) {
			return abs(i - j);
		} else {
			int a1 = solve(i + 1, j, colors, dp);
			int a2 = solve(i, j - 1, colors, dp);
			dp[i] = max(a1, a2);
			return dp[i];
		}
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)