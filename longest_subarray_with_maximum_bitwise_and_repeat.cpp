class Solution {
   public:
	int longestSubarray(vector<int>& nums) {
		int ans = 1, curr = 1, largest = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > largest) {
				largest = nums[i];
				curr = 1;
				ans = 1;
			} else if (nums[i] < largest) {
				curr = 0;
			} else {
				curr++;
				ans = max(ans, curr);
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)