class Solution {
   public:
	int maxProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		return max((nums[0] - 1) * (nums[1] - 1),
		           (nums[n - 1] - 1) * (nums[n - 2] - 1));
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(1)