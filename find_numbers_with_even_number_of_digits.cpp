class Solution {
   public:
	int findNumbers(vector<int>& nums) {
		int ans = 0;

		for (int num : nums) {
			ans += int(log10(num)) % 2 == 1;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)