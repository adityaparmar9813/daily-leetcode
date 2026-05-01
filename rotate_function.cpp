class Solution {
   public:
	int maxRotateFunction(vector<int>& nums) {
		int n = nums.size();
		long sum = 0, window = 0;

		for (int i = 0; i < n; i++) {
			sum += nums[i];
			window += (long)i * nums[i];
		}

		long result = window;

		for (int k = 1; k < n; k++) {
			window = window + sum - 1l * n * nums[n - k];
			result = max(result, window);
		}

		return result;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)