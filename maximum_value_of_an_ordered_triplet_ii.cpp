class Solution {
   public:
	long long maximumTripletValue(vector<int>& nums) {
		int n = nums.size(), largest = nums[0], diff = largest - nums[1];
		long long ans = 0;

		for (int i = 2; i < n; i++) {
			ans = max(ans, nums[i] * 1ll * diff);
			largest = max(largest, nums[i - 1]);
			diff = max(diff, largest - nums[i]);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)