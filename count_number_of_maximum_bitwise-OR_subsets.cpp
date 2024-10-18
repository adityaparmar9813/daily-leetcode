class Solution {
  public:
	int n;
	int max_OR;

	int solve(int i, int acc_or, vector<int> &nums) {
		if (i < 0) {
			return (acc_or == max_OR) ? 1 : 0;
		}
		int skip = solve(i - 1, acc_or, nums);
		int take = solve(i - 1, acc_or | nums[i], nums);

		return skip + take;
	}

	int countMaxOrSubsets(vector<int> &nums) {
		n = nums.size();
		max_OR = accumulate(nums.begin(), nums.end(), 0, bit_or<>());
		return solve(n - 1, 0, nums);
	}
};

// Time Complexity : O(2 ^ n)
// Space Complexity : O(n)