class Solution {
   public:
	vector<bool> prefixesDivBy5(vector<int>& nums) {
		int curr = 0, n = nums.size();
		vector<bool> ans(n, false);

		for (int i = 0; i < n; i++) {
			curr = (curr * 2 + nums[i]) % 10;
			if (curr % 5 == 0) {
				ans[i] = true;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)