class Solution {
   public:
	int longestMonotonicSubarray(vector<int>& nums) {
		int n = nums.size(), i = 0, ans = 1;
		int inc = 1, dec = 1;

		for (i = 1; i < n; i++) {
			if (nums[i] > nums[i - 1]) {
				inc++;
				dec = 1;
			} else if (nums[i] < nums[i - 1]) {
				inc = 1;
				dec++;
			} else {
				inc = 1;
				dec = 1;
			}
			ans = max({ans, dec, inc});
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)