class Solution {
   public:
	int largestPerimeter(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater<int>());

		for (int i = 0; i < nums.size() - 2; i++) {
			if (nums[i + 1] + nums[i + 2] > nums[i]) {
				return nums[i] + nums[i + 1] + nums[i + 2];
			}
		}

		return 0;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(1)