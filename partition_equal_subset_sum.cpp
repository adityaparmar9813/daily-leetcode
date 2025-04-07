class Solution {
   public:
	vector<vector<int>> dp;

	bool solve(vector<int>& nums, int index, int s1, int s2) {
		if (index == nums.size()) {
			return s1 == s2;
		}

		if (dp[index][s1] != -1) {
			return dp[index][s1];
		}

		return dp[index][s1] = solve(nums, index + 1, s1 + nums[index], s2) ||
		                       solve(nums, index + 1, s1, s2 + nums[index]);
	}

	bool canPartition(vector<int>& nums) {
		dp.resize(nums.size(), vector<int>(2e4 + 1, -1));
		return solve(nums, 0, 0, 0);
	}
};

// Time Complexity: O(n * sum)
// Space Complexity: O(n * sum)