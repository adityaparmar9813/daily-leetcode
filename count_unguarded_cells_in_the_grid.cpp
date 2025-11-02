class Solution {
   public:
	int countUnguarded(int m, int n, vector<vector<int>>& guards,
	                   vector<vector<int>>& walls) {
		vector<vector<int>> grid(m, vector<int>(n, 0));

		for (auto& guard : guards) grid[guard[0]][guard[1]] = 1;
		for (auto& wall : walls) grid[wall[0]][wall[1]] = 2;

		vector<vector<bool>> guarded(m, vector<bool>(n, false));

		for (int i = 0; i < m; i++) {
			bool watch = false;

			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1)
					watch = true;
				else if (grid[i][j] == 2)
					watch = false;
				else if (watch)
					guarded[i][j] = true;
			}

			watch = false;

			for (int j = n - 1; j >= 0; j--) {
				if (grid[i][j] == 1)
					watch = true;
				else if (grid[i][j] == 2)
					watch = false;
				else if (watch)
					guarded[i][j] = true;
			}
		}

		for (int j = 0; j < n; j++) {
			bool watch = false;

			for (int i = 0; i < m; i++) {
				if (grid[i][j] == 1)
					watch = true;
				else if (grid[i][j] == 2)
					watch = false;
				else if (watch)
					guarded[i][j] = true;
			}

			watch = false;

			for (int i = m - 1; i >= 0; i--) {
				if (grid[i][j] == 1)
					watch = true;
				else if (grid[i][j] == 2)
					watch = false;
				else if (watch)
					guarded[i][j] = true;
			}
		}

		int count = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0 && !guarded[i][j]) {
					count++;
				}
			}
		}

		return count;
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n ^ 2)