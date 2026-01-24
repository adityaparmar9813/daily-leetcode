class Solution {
   public:
	int minPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int ans = 0, n = nums.size();

		for (int i = 0; i < n / 2; i++) {
			ans = max(ans, nums[i] + nums[n - i - 1]);
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)