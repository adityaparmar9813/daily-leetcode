class Solution {
   public:
	vector<vector<int>> memo;
	int totalCols;
	const int MOD = 1e9 + 7;

	int numTilings(int n) {
		totalCols = n;
		memo = vector<vector<int>>(n, vector<int>(2, -1));
		vector<vector<int>> grid(2, vector<int>(n, -1));
		return countWays(0, grid, 0);
	}

	int countWays(int col, vector<vector<int>>& grid, int filledCells) {
		if (filledCells == 2 * totalCols) {
			return 1;
		}
		if (col >= totalCols) {
			return 0;
		}
		if (memo[col][filledCells % 2] != -1) {
			return memo[col][filledCells % 2];
		}

		int result = 0;

		if (grid[0][col] == -1 && grid[1][col] == -1) {
			grid[0][col] = grid[1][col] = 1;
			result = (result + countWays(col + 1, grid, filledCells + 2)) % MOD;
			grid[0][col] = grid[1][col] = -1;

			if (col < totalCols - 1) {
				grid[0][col] = grid[1][col] = grid[0][col + 1] = 2;
				result =
				    (result + countWays(col + 1, grid, filledCells + 3)) % MOD;
				grid[0][col] = grid[1][col] = grid[0][col + 1] = -1;

				grid[0][col] = grid[1][col] = grid[1][col + 1] = 3;
				result =
				    (result + countWays(col + 1, grid, filledCells + 3)) % MOD;
				grid[0][col] = grid[1][col] = grid[1][col + 1] = -1;

				grid[0][col] = grid[1][col] = grid[0][col + 1] =
				    grid[1][col + 1] = 4;
				result =
				    (result + countWays(col + 2, grid, filledCells + 4)) % MOD;
				grid[0][col] = grid[1][col] = grid[0][col + 1] =
				    grid[1][col + 1] = -1;
			}
		} else {
			int row = (grid[0][col] == -1) ? 0 : 1;

			if (col < totalCols - 1) {
				grid[row][col] = grid[row][col + 1] = 5;
				result =
				    (result + countWays(col + 1, grid, filledCells + 2)) % MOD;
				grid[row][col] = grid[row][col + 1] = -1;

				grid[row][col] = grid[row][col + 1] = grid[1 - row][col + 1] =
				    6;
				result =
				    (result + countWays(col + 2, grid, filledCells + 3)) % MOD;
				grid[row][col] = grid[row][col + 1] = grid[1 - row][col + 1] =
				    -1;
			}
		}

		return memo[col][filledCells % 2] = result;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n)