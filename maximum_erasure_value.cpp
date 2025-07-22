class Solution {
   public:
	int maximumUniqueSubarray(vector<int>& nums) {
		int r = 0;
		vector<bool> st(1e5 + 1, false);
		int ans = 0, curr = 0;

		for (int l = 0; l < nums.size(); l++) {
			while (r < nums.size() && st[nums[r]] == false) {
				curr += nums[r];
				st[nums[r++]] = true;
			}
			ans = max(ans, curr);
			curr -= nums[l];
			st[nums[l]] = false;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)