class Solution {
  public:
	inline bool findParity(int num) { return num % 2 == 0; }

	vector<bool> isArraySpecial(vector<int> &nums,
								vector<vector<int>> &queries) {
		int n = nums.size(), q = queries.size();
		vector<int> prefixParity(n);
		vector<bool> ans(q);

		int l = 0;
		bool prevParity = findParity(nums[0]);

		for (int r = 1; r < n; r++) {
			if (findParity(nums[r]) != prevParity) {
				prevParity = !prevParity;
			} else {
				for (int i = l; i <= r - 1; i++) {
					prefixParity[i] = r - 1;
				}
				l = r;
			}
		}

		for (int i = l; i < n; i++) {
			prefixParity[i] = n - 1;
		}

		for (int i = 0; i < q; i++) {
			int l = queries[i][0], r = queries[i][1];
			ans[i] = (prefixParity[l] >= r);
		}

		return ans;
	}
};

// Time Complexity: O(n + q)
// Space Complexity: O(n)