
class Solution {
   public:
	int largestMagicSquare(vector<vector<int>>& grid) {
		int R = grid.size(), C = grid[0].size();

		vector<vector<int>> row(R, vector<int>(C + 1, 0));
		vector<vector<int>> col(R + 1, vector<int>(C, 0));

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) row[i][j + 1] = row[i][j] + grid[i][j];

		for (int j = 0; j < C; j++)
			for (int i = 0; i < R; i++) col[i + 1][j] = col[i][j] + grid[i][j];

		int ans = 1;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				int maxSize = min(R - i, C - j);
				for (int sz = maxSize; sz > ans; sz--) {
					if (isMagic(grid, row, col, i, j, sz)) {
						ans = sz;
						break;
					}
				}
			}
		}
		return ans;
	}

	bool isMagic(vector<vector<int>>& g, vector<vector<int>>& r,
	             vector<vector<int>>& c, int x, int y, int len) {
		int target = r[x][y + len] - r[x][y];

		for (int i = 0; i < len; i++)
			if (r[x + i][y + len] - r[x + i][y] != target) return false;

		for (int j = 0; j < len; j++)
			if (c[x + len][y + j] - c[x][y + j] != target) return false;

		int d1 = 0, d2 = 0;
		for (int k = 0; k < len; k++) {
			d1 += g[x + k][y + k];
			d2 += g[x + len - 1 - k][y + k];
		}
		return d1 == target && d2 == target;
	}
};

// Time Complexity: O(R * C)
// Space Complexity: O(R * C)