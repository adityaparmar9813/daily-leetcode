class Solution {
   public:
	int maximumDifference(vector<int>& nums) {
		int mini = INT_MAX, ans = -1;

		for (int num : nums) {
			if (num > mini) {
				ans = max(ans, num - mini);
			}
			mini = min(mini, num);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)