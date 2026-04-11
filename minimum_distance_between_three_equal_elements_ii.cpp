class Solution {
   public:
	int minimumDistance(vector<int>& nums) {
		int n = nums.size();
		vector<int> prev(n + 1, -1);

		for (int i = 0; i < n; i++) {
			int newVal = prev[nums[i]] == -1 ? -1 : prev[nums[i]];
			prev[nums[i]] = i;
			nums[i] = newVal;
		}

		int ans = 1e9;

		for (int i = 2; i < n; i++) {
			if (nums[i] != -1 && nums[nums[i]] != -1) {
				ans = min(ans, 2 * (i - nums[nums[i]]));
			}
		}

		return ans == 1e9 ? -1 : ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)