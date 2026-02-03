class Solution {
   public:
	bool isTrionic(vector<int>& nums) {
		if (nums[1] <= nums[0]) {
			return false;
		}

		int direction = 1, switchCount = 0;

		for (int i = 2; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) {
				return false;
			} else if (direction == 1 && nums[i] < nums[i - 1]) {
				direction = -1;
				switchCount++;
			} else if (direction == -1 && nums[i] > nums[i - 1]) {
				direction = 1;
				switchCount++;
			}
		}

		return switchCount == 2;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)