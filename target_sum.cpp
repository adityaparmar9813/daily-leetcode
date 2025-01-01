class Solution {
   public:
	int solve(vector<int>& nums, int index, int target,
	          unordered_map<int, int>& dp) {
		if (index == nums.size()) {
			return target == 0 ? 1 : 0;
		}

		int key = index * 10001 + target;

		if (dp.find(key) != dp.end()) {
			return dp[key];
		}

		int add = solve(nums, index + 1, target - nums[index], dp);
		int subtract = solve(nums, index + 1, target + nums[index], dp);

		return dp[key] = add + subtract;
	}

	int findTargetSumWays(vector<int>& nums, int target) {
		unordered_map<int, int> dp;
		return solve(nums, 0, target, dp);
	}
};

// Time  Complexity: O(n * target)
// Space Complexity: O(n * target)