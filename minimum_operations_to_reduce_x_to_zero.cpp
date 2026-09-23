class Solution {
   public:
	int minOperations(vector<int>& nums, int x) {
		int n = nums.size();
		vector<int> prefix(n), suffix(n + 1);

		prefix[0] = nums[0];

		for (int i = 1; i < n; i++) {
			prefix[i] = prefix[i - 1] + nums[i];
		}

		for (int i = n - 1; i >= 0; i--) {
			suffix[i] = suffix[i + 1] + nums[i];
		}

		int r = n - 1, ans = 1e9;

		while (r >= 0 && suffix[r] < x) {
			r--;
		}

		if (r >= 0 && suffix[r] == x) {
			ans = min(ans, n - r);
		}

		for (int l = 0; l < n && prefix[l] <= x; l++) {
			r = max(r, l + 1);

			while (r < n && prefix[l] + suffix[r] > x) {
				r++;
			}

			if (r <= n && prefix[l] + suffix[r] == x) {
				ans = min(ans, l + 1 + n - r);
			}
		}

		return ans == 1e9 ? -1 : ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)