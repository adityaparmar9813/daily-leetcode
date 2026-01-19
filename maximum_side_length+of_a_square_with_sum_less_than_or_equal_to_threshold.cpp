class Solution {
   public:
	int maxSideLength(vector<vector<int>>& mat, int threshold) {
		int n = mat.size(), m = mat[0].size();
		int low = 1, high = min(n, m), ans = 0;

		while (low <= high) {
			int k = (low + high) / 2;
			vector<int> col(m, 0);
			bool ok = false;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					col[j] += mat[i][j];
					if (i >= k) {
						col[j] -= mat[i - k][j];
					}
				}

				if (i + 1 < k) {
					continue;
				}

				int sum = 0;
				for (int j = 0; j < m; j++) {
					sum += col[j];

					if (j >= k) {
						sum -= col[j - k];
					}
					if (j + 1 >= k && sum <= threshold) {
						ok = true;
						break;
					}
				}

				if (ok) {
					break;
				}
			}

			if (ok) {
				ans = k;
				low = k + 1;
			} else {
				high = k - 1;
			}
		}

		return ans;
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n)