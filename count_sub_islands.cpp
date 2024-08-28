class Solution {
  public:
	int r, c;
	vector<int> dir = {0, 1, 0, -1, 0};

	bool isOutside(int i, int j) { return i < 0 || i >= r || j < 0 || j >= c; }

	bool dfs(int i, int j, int mark, vector<vector<int>> &grid1,
			 vector<vector<int>> &grid2) {
		if (grid1[i][j] != 1) {
			return 0;
		}

		grid2[i][j] = mark;
		bool isSub = true;

		for (int d = 0; d < 4; d++) {
			int s = i + dir[d], t = j + dir[d + 1];

			if (isOutside(s, t) || grid2[s][t] != 1) {
				continue;
			}
			if (grid1[s][t] != 1 || !dfs(s, t, mark, grid1, grid2)) {
				isSub = false;
			}
		}
		return isSub;
	}

	int countSubIslands(vector<vector<int>> &grid1,
						vector<vector<int>> &grid2) {
		r = grid1.size(), c = grid1[0].size();
		int count = 0, mark = 2;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid2[i][j] == 1) {
					count += dfs(i, j, mark++, grid1, grid2);
				}
			}
		}
		return count;
	}
};

// Time Complexity : O(r * c)
// Space Complexity : O(r * c)