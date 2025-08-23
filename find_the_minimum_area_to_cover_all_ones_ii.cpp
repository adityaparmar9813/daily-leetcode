class Solution {
   public:
	int minArea(int i, int j, int w, int h, vector<vector<int>>& grid) {
		vector<int> a, b;

		for (int row = i; row < i + h; row++) {
			for (int col = j; col < j + w; col++) {
				if (grid[row][col] == 1) {
					a.push_back(row);
					b.push_back(col);
				}
			}
		}

		if (a.empty() || b.empty()) {
			return 0;
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		return (a.back() - a[0] + 1) * (b.back() - b[0] + 1);
	}

	int solve(int i, int j, int w, int h, int ct, vector<vector<int>>& grid) {
		if (ct > 1) {
			return 0;
		}
		int res = INT_MAX;

		for (int x = 1; x < w; x++) {
			int tmp1 = solve(i, j, x, h, ct + 1, grid);
			int tmp2 = solve(i, j + x, w - x, h, ct + 1, grid);

			int ar1 = minArea(i, j, x, h, grid);
			int ar2 = minArea(i, j + x, w - x, h, grid);

			if (ct == 0) {
				res = min({res, tmp1 + ar2, tmp2 + ar1});
			} else if (ct == 1) {
				res = min(res, ar1 + ar2);
			}
		}

		for (int x = 1; x < h; x++) {
			int tmp1 = solve(i, j, w, x, ct + 1, grid);
			int tmp2 = solve(i + x, j, w, h - x, ct + 1, grid);

			int ar1 = minArea(i, j, w, x, grid);
			int ar2 = minArea(i + x, j, w, h - x, grid);

			if (ct == 0) {
				res = min({res, tmp1 + ar2, tmp2 + ar1});
			} else if (ct == 1) {
				res = min(res, ar1 + ar2);
			}
		}

		return res;
	}

	int minimumSum(vector<vector<int>>& grid) {
		int h = grid.size(), w = grid[0].size();
		return solve(0, 0, w, h, 0, grid);
	}
};

// Time Complexity: O(n ^ 4 * log(n))
// Space Complexity: O(n ^ 4)
