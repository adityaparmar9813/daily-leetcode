class Solution {
   public:
	bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
		int n = nums.size();
		vector<int> store(n + 2, 0);

		for (int i = 0; i < k; i++) {
			int l = queries[i][0], r = queries[i][1], val = queries[i][2];
			store[l] += val;
			store[r + 1] -= val;
		}

		int curr = 0;

		for (int i = 0; i < n; i++) {
			curr += store[i];
			if (nums[i] - curr > 0) {
				return false;
			}
		}

		return true;
	}

	int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
		int l = 0, r = queries.size(), ans = -1;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (check(nums, queries, mid)) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)