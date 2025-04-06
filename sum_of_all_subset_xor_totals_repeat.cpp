class Solution {
   public:
	int solve(vector<int>& nums, int index, int curr) {
		if (index == nums.size()) {
			return curr;
		}

		int take = solve(nums, index + 1, curr ^ nums[index]);
		int notTake = solve(nums, index + 1, curr);

		return take + notTake;
	}

	int subsetXORSum(vector<int>& nums) { return solve(nums, 0, 0); }
};

// Time Complexity: O(2 ^ n)
// Space Complexity: O(n)