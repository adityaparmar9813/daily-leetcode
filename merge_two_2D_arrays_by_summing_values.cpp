class Solution {
   public:
	vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
	                                vector<vector<int>>& nums2) {
		vector<vector<int>> res;
		int i = 0, j = 0, m = nums1.size(), n = nums2.size();

		while (i < m && j < n) {
			if (nums1[i][0] == nums2[j][0]) {
				res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
				i++;
				j++;
			} else if (nums1[i][0] < nums2[j][0]) {
				res.push_back(nums1[i]);
				i++;
			} else {
				res.push_back(nums2[j]);
				j++;
			}
		}

		while (i < m) {
			res.push_back(nums1[i++]);
		}

		while (j < n) {
			res.push_back(nums2[j++]);
		}

		return res;
	}
};

// Time Complexity: O(m + n)
// Space Complexity: O(m + n)