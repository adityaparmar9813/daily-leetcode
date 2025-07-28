class Solution {
   public:
	int solve(vector<int>& nums, int index, int maxOr, int curr) {
		if (index == nums.size()) {
			return curr == maxOr;
		}
		if (curr == maxOr) {
			return 1 << (nums.size() - index);
		}

		int take = solve(nums, index + 1, maxOr, curr | nums[index]);
		int notTake = solve(nums, index + 1, maxOr, curr);

		return take + notTake;
	}

	int countMaxOrSubsets(vector<int>& nums) {
		int maxOr = 0;

		for (int num : nums) {
			maxOr |= num;
		}

		return solve(nums, 0, maxOr, 0);
	}
};

// Time Complexity: O(2 ^ n)
// Space Complexity: O(n)