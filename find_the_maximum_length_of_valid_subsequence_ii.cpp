class Solution {
   public:
	int maximumLength(vector<int>& nums, int k) {
		for (int i = 0; i < nums.size(); i++) {
			nums[i] %= k;
		}

		int ans = 1;
		vector<int> mp(1001, -1);

		for (int pos = 0; pos < k; pos++) {
			mp.assign(1001, -1);

			for (int i = 0; i < nums.size(); i++) {
				int find = nums[i] <= pos ? pos - nums[i] : k + pos - nums[i];

				if (mp[find] != -1) {
					ans = max(ans, 1 + mp[find]);
					mp[nums[i]] = max(mp[nums[i]], 1 + mp[find]);
				}
				mp[nums[i]] = max(1, mp[nums[i]]);
			}
		}
		return ans;
	}
};

// Time Complexity: O(n * k)
// Space Complexity: O(k)