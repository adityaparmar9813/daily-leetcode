class Solution {
   public:
	int minElement(vector<int>& nums) {
		int ans = 1e9;

		for (int num : nums) {
			int sum = 0;

			while (num != 0) {
				sum += (num % 10);
				num /= 10;
			}

			ans = min(ans, sum);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)