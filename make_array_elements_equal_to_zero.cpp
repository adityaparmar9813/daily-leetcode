class Solution {
   public:
	int countValidSelections(vector<int>& nums) {
		int total = accumulate(nums.begin(), nums.end(), 0);
		int leftSum = 0, ans = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				int rightSum = total - leftSum;

				if (leftSum == rightSum) {
					ans += 2;
				} else if (abs(leftSum - rightSum) == 1) {
					ans += 1;
				}
			}
			leftSum += nums[i];
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)