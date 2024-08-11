class Solution {
public:
  int rows;
  int cols;
  vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void dfs(int i, int j, vector<vector<int>> &temp) {
    if (i < 0 || j < 0 || i >= rows || j >= cols || temp[i][j] == 0) {
      return;
    }

    temp[i][j] = 0;
    for (int k = 0; k < 4; k++) {
      dfs(i + dir[k][0], j + dir[k][1], temp);
    }
  }

  int countDfs(vector<vector<int>> &temp) {
    int land = 0;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (temp[i][j] == 1) {
          dfs(i, j, temp);
          land++;
        }
      }
    }
    return land;
  }

  int minDays(vector<vector<int>> &grid) {
    vector<vector<int>> temp = grid;
    rows = grid.size();
    cols = grid[0].size();
    int land = 0;
    land = countDfs(temp);

    if (land == 1) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          temp = grid;

          if (temp[i][j] == 1) {
            temp[i][j] = 0;

            if (countDfs(temp) != 1) {
              return 1;
            }
            temp[i][j] = 1;
          }
        }
      }
      return 2;
    }
    return 0;
  }
};

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)
