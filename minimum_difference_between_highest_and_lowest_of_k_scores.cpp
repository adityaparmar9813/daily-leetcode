class Solution {
   public:
	int minimumDifference(vector<int>& nums, int k) {
		int ans = 1e9, n = nums.size();
		sort(nums.begin(), nums.end());

		for (int i = k - 1; i < n; i++) {
			ans = min(ans, nums[i] - nums[i - k + 1]);
		}

		return ans;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(1)