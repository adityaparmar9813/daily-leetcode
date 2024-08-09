class Solution {
public:
  bool basic(int a) { return a > 0 && a < 10; }

  bool isMagicSquare(vector<vector<int>> &grid, int a, int b) {
    vector<bool> checker(10, false);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int val = grid[a + i][b + j];
        if (!basic(val) || checker[val]) {
          return false;
        }
        checker[val] = true;
      }
    }

    int sum = grid[a][b] + grid[a][b + 1] + grid[a][b + 2];

    for (int i = 1; i < 3; i++) {
      int rowSum = grid[a + i][b] + grid[a + i][b + 1] + grid[a + i][b + 2];
      if (rowSum != sum) {
        return false;
      }
    }

    for (int j = 0; j < 3; j++) {
      int colSum = grid[a][b + j] + grid[a + 1][b + j] + grid[a + 2][b + j];
      if (colSum != sum) {
        return false;
      }
    }

    int diag1Sum = grid[a][b] + grid[a + 1][b + 1] + grid[a + 2][b + 2];
    int diag2Sum = grid[a][b + 2] + grid[a + 1][b + 1] + grid[a + 2][b];

    if (diag1Sum != sum || diag2Sum != sum) {
      return false;
    }
    return true;
  }

  int numMagicSquaresInside(vector<vector<int>> &grid) {
    if (grid.size() < 3 || grid[0].size() < 3) {
      return 0;
    }

    int ans = 0;
    for (int i = 0; i < grid.size() - 2; i++) {
      for (int j = 0; j < grid[0].size() - 2; j++) {
        if (isMagicSquare(grid, i, j))
          ans++;
      }
    }
    return ans;
  }
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(1)
