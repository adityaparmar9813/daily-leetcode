class Solution {
   public:
	void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i,
	         int j) {
		visited[i][j] = true;
		int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		for (auto& d : dirs) {
			int ni = i + d[0], nj = j + d[1];

			if (ni >= 0 && ni < heights.size() && nj >= 0 &&
			    nj < heights[0].size() && !visited[ni][nj] &&
			    heights[ni][nj] >= heights[i][j]) {
				dfs(heights, visited, ni, nj);
			}
		}
	}

	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		int m = heights.size(), n = heights[0].size();
		vector<vector<bool>> pac(m, vector<bool>(n, false)),
		    atl(m, vector<bool>(n, false));

		for (int i = 0; i < m; i++) {
			dfs(heights, pac, i, 0);
			dfs(heights, atl, i, n - 1);
		}

		for (int j = 0; j < n; j++) {
			dfs(heights, pac, 0, j);
			dfs(heights, atl, m - 1, j);
		}

		vector<vector<int>> res;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (pac[i][j] && atl[i][j]) res.push_back({i, j});
			}
		}

		return res;
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n ^ 2)