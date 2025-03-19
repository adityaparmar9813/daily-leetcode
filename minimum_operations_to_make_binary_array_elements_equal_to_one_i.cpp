class Solution {
   public:
	int minOperations(vector<int>& nums) {
		int n = nums.size(), ans = 0;

		for (int i = 0; i < n - 2; i++) {
			if (nums[i] == 0) {
				nums[i + 1] = nums[i + 1] == 0 ? 1 : 0;
				nums[i + 2] = nums[i + 2] == 0 ? 1 : 0;
				ans++;
			}
		}

		return nums[n - 1] == 1 && nums[n - 2] == 1 ? ans : -1;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)