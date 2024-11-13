class Solution {
  public:
	long long countFairPairs(vector<int> &nums, int lower, int upper) {
		sort(nums.begin(), nums.end());
		long long ans = 0;

		for (int i = 0; i < nums.size(); ++i) {
			int lowerLim = lower - nums[i];
			int upperLim = upper - nums[i];

			auto lower_it =
				lower_bound(nums.begin() + i + 1, nums.end(), lowerLim);
			auto upper_it =
				upper_bound(nums.begin() + i + 1, nums.end(), upperLim);

			ans += (upper_it - lower_it);
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)