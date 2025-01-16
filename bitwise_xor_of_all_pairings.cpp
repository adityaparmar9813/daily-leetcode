class Solution {
   public:
	int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size(), ans = 0;

		if (m % 2 != 0) {
			for (int num : nums2) {
				ans ^= num;
			}
		}

		if (n % 2 != 0) {
			for (int num : nums1) {
				ans ^= num;
			}
		}

		return ans;
	}
};

// Time Complexity  : O(m + n)
// Space Complexity : O(1)