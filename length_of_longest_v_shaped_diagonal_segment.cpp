class Solution {
   public:
	int n, m;
	vector<vector<int>> grid;
	vector<pair<int, int>> directions = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

	int get_clock_wise_turn(int dir) {
		if (dir == 0) {
			return 1;
		}
		if (dir == 1) {
			return 3;
		}
		if (dir == 2) {
			return 0;
		}
		if (dir == 3) {
			return 2;
		}

		return -1;
	}

	int solve(int i, int j, int dir, int turned, int step) {
		if (i < 0 || j < 0 || i >= n || j >= m) {
			return 0;
		}

		int expected = (step == 0) ? 1 : ((step % 2 == 1) ? 2 : 0);

		if (grid[i][j] != expected) {
			return 0;
		}

		int best = 1 + solve(i + directions[dir].first,
		                     j + directions[dir].second, dir, turned, step + 1);
		if (!turned) {
			int new_dir = get_clock_wise_turn(dir);
			best = max(best, 1 + solve(i + directions[new_dir].first,
			                           j + directions[new_dir].second, new_dir,
			                           1, step + 1));
		}

		return best;
	}

	int lenOfVDiagonal(vector<vector<int>>& grid) {
		this->grid = grid;
		n = grid.size();
		m = grid[0].size();
		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					for (int dir = 0; dir < 4; dir++) {
						ans = max(ans, solve(i, j, dir, 0, 0));
					}
				}
			}
		}

		return ans;
	}
};

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)