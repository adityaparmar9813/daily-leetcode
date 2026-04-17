class Solution {
   public:
	inline int reverse(int x) {
		int y = 0;
		while (x > 0) {
			y = y * 10 + x % 10;
			x /= 10;
		}
		return y;
	}

	int minMirrorPairDistance(vector<int>& nums) {
		unordered_map<int, int> mp;
		int n = nums.size();
		int ans = n + 1;

		for (int i = 0; i < n; i++) {
			if (mp.count(nums[i])) {
				ans = min(ans, i - mp[nums[i]]);
			}
			mp[reverse(nums[i])] = i;
		}

		return ans > n ? -1 : ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)