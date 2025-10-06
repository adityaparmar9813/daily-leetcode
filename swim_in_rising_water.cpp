class Solution {
   public:
	int find(vector<int>& parent, int x) {
		return parent[x] == x ? x : parent[x] = find(parent, parent[x]);
	}

	void unite(vector<int>& parent, int x, int y) {
		parent[find(parent, x)] = find(parent, y);
	}

	int swimInWater(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<tuple<int, int, int>> edges;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i > 0)
					edges.push_back({max(grid[i][j], grid[i - 1][j]), i * n + j,
					                 (i - 1) * n + j});
				if (j > 0)
					edges.push_back({max(grid[i][j], grid[i][j - 1]), i * n + j,
					                 i * n + j - 1});
			}
		}

		sort(edges.begin(), edges.end());
		vector<int> parent(m * n);
		iota(parent.begin(), parent.end(), 0);

		for (auto [cost, u, v] : edges) {
			unite(parent, u, v);
			if (find(parent, 0) == find(parent, m * n - 1)) return cost;
		}

		return grid[0][0];
	}
};