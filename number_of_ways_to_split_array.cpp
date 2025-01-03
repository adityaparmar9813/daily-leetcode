class Solution {
   public:
	int waysToSplitArray(vector<int>& nums) {
		long long totalSum = accumulate(nums.begin(), nums.end(), 0ll);
		long long currSum = 0;
		int ans = 0;

		for (int i = 0; i < nums.size() - 1; i++) {
			currSum += nums[i];
			totalSum -= nums[i];

			if (currSum >= totalSum) {
				ans++;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)