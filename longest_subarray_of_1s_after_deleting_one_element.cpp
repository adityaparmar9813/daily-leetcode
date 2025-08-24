class Solution {
   public:
	int longestSubarray(vector<int>& nums) {
		int l = 0, r = 0, zeroCount = 0, ans = 0;

		while (r < nums.size()) {
			if (nums[r] == 0) {
				zeroCount++;
			}

			while (zeroCount > 1) {
				if (nums[l] == 0) {
					zeroCount--;
				}
				l++;
			}

			ans = max(ans, r - l);
			r++;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)