class Solution {
   public:
	int differenceOfSums(int n, int m) {
		int l = 1, r = n;
		int ans = -1;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (mid * m <= n) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		return n * (n + 1) / 2 - 2 * m * (ans) * (ans + 1) / 2;
	}
};

// Time Complexity: O(log n)
// Space Complexity: O(1)