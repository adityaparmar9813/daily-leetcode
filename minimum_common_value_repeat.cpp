class Solution {
   public:
	int getCommon(vector<int>& nums1, vector<int>& nums2) {
		int i = 0, j = 0, n = nums1.size(), m = nums2.size();

		while (i < n && j < m) {
			if (nums1[i] < nums2[j]) {
				i++;
			} else if (nums1[i] > nums2[j]) {
				j++;
			} else {
				return nums1[i];
			}
		}

		return -1;
	}
};

// Time Complexity: O(n + m)
// Space Complexity: O(1)