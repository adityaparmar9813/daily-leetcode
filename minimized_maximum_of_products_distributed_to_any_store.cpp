class Solution {
  public:
	bool check(int n, vector<int> &quantities, int num) {
		for (int quantity : quantities) {
			n -= ceil(quantity / (double)num);
		}
		return n >= 0;
	}

	int minimizedMaximum(int n, vector<int> &quantities) {
		int l = 1, r = *max_element(quantities.begin(), quantities.end()),
			ans = r;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (check(n, quantities, mid)) {
				ans = min(ans, mid);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		return ans;
	}
};

// Time Complexity : O(n * log(max(quantities)))
// Space Complexity : O(1)