class Solution {
public:
  char direction;
  vector<vector<int>> ans;
  int total;

  void solve(int rows, int cols, int row, int col, vector<vector<int>> &visited,
             char move, int &count) {
    if (count >= total) {
      return;
    }

    if (row >= 0 && row < rows && col >= 0 && col < cols &&
        visited[row][col] == 0) {
      ans.push_back({row, col});
      visited[row][col] = 1;
      count++;
    }

    if (move == 'u') {
      if ((row >= 0 && row < rows && (col + 1) >= 0 && (col + 1) < cols &&
           visited[row][col + 1] == 0) ||
          !(row >= 0 && row < rows && (col + 1) >= 0 && (col + 1) < cols)) {
        solve(rows, cols, row, col + 1, visited, 'r', count);
      } else {
        solve(rows, cols, row - 1, col, visited, 'u', count);
      }
    }

    if (move == 'r') {
      if (((row + 1) >= 0 && (row + 1) < rows && col >= 0 && col < cols &&
           visited[row + 1][col] == 0) ||
          !((row + 1) >= 0 && (row + 1) < rows && col >= 0 && col < cols)) {
        solve(rows, cols, row + 1, col, visited, 'd', count);
      } else {
        solve(rows, cols, row, col + 1, visited, 'r', count);
      }
    }

    if (move == 'd') {
      if ((row >= 0 && row < rows && (col - 1) >= 0 && (col - 1) < cols &&
           visited[row][col - 1] == 0) ||
          !(row >= 0 && row < rows && (col - 1) >= 0 && (col - 1) < cols)) {
        solve(rows, cols, row, col - 1, visited, 'l', count);
      } else {
        solve(rows, cols, row + 1, col, visited, 'd', count);
      }
    }

    if (move == 'l') {
      if (((row - 1) >= 0 && (row - 1) < rows && col >= 0 && col < cols &&
           visited[row - 1][col] == 0) ||
          !((row - 1) >= 0 && (row - 1) < rows && col >= 0 && col < cols)) {
        solve(rows, cols, row - 1, col, visited, 'u', count);
      } else {
        solve(rows, cols, row, col - 1, visited, 'l', count);
      }
    }
  }

  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    total = rows * cols;
    int count = 0;
    solve(rows, cols, rStart, cStart, visited, 'u', count);
    return ans;
  }
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n ^ 2)
