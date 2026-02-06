class Solution {
   public:
	int minRemoval(vector<int>& nums, int k) {
		int n = nums.size(), ans = n;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < n; i++) {
			int l = i, r = n - 1, res = i;

			while (l <= r) {
				int mid = (l + r) / 2;

				if (nums[i] * 1ll * k >= nums[mid]) {
					res = max(res, mid);
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}

			ans = min(ans, i + (n - res - 1));
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)