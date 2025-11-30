class Solution {
   public:
	int minSubarray(vector<int>& nums, int p) {
		int n = nums.size();
		long long sum = accumulate(nums.begin(), nums.end(), 0ll);

		int rem = sum % p;
		if (rem == 0) return 0;

		unordered_map<int, int> mp;
		mp[0] = -1;

		int res = n;
		long long prefixSum = 0;

		for (int i = 0; i < n; i++) {
			prefixSum += nums[i];
			int target = (prefixSum % p - rem + p) % p;

			if (mp.find(target) != mp.end()) {
				res = min(res, i - mp[target]);
			}

			mp[prefixSum % p] = i;
		}

		return res != n ? res : -1;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)