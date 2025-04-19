class Solution {
   public:
	long long countFairPairs(vector<int>& nums, int lower, int upper) {
		sort(nums.begin(), nums.end());
		long long ans = 0;

		for (int i = 0; i < nums.size(); ++i) {
			auto lower_it =
			    lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
			auto upper_it =
			    upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);

			ans += (upper_it - lower_it);
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)