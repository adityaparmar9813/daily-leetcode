class Solution {
   public:
	bool check(vector<int>& nums, int k, int mid) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= mid) {
				k--;
				i++;
			}
		}

		return k <= 0;
	}

	int minCapability(vector<int>& nums, int k) {
		int l = 0, r = *max_element(nums.begin(), nums.end()), ans;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (check(nums, k, mid)) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)