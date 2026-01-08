class Solution {
   public:
	vector<vector<int>> dp;

	int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
		if (i == nums1.size() || j == nums2.size()) {
			return 0;
		}
		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		int take = nums1[i] * nums2[j] + solve(nums1, nums2, i + 1, j + 1);
		int notTake1 = solve(nums1, nums2, i + 1, j);
		int notTake2 = solve(nums1, nums2, i, j + 1);

		return dp[i][j] = max({take, notTake1, notTake2});
	}

	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		dp.resize(nums1.size(), vector<int>(nums2.size(), -1));
		int res = solve(nums1, nums2, 0, 0);

		if (res == 0) {
			sort(nums1.begin(), nums1.end());
			sort(nums2.begin(), nums2.end());

			return max(nums1[0] * nums2.back(), nums1.back() * nums2[0]);
		}

		return res;
	}
};

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)