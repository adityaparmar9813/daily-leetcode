class Solution {
   public:
	long long countGood(vector<int>& nums, int k) {
		int n = nums.size();
		unordered_map<int, int> mp;
		long long ans = 0, count = 0;

		for (int r = 0, l = 0; r < n; r++) {
			const int x = nums[r];
			count += mp[x]++;

			while (count >= k) {
				ans += (n - r);
				count -= --mp[nums[l]];
				l++;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)