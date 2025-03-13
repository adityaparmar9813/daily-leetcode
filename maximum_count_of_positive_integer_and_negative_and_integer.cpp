class Solution {
   public:
	int maximumCount(vector<int>& nums) {
		int n = nums.size();
		int left = 0;
		int right = n - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > 0) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		int positiveCount = n - left;

		left = 0;
		right = n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < 0) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		int negativeCount = right + 1;

		return max(positiveCount, negativeCount);
	}
};

// Time Complexity: O(log(n))
// Space Complexity : O(1)