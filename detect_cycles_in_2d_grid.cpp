constexpr int N = 500 * 500;
int Rt[N], Rk[N];

class UnionFind {
	int *root, *rank;

   public:
	UnionFind(int n) {
		root = Rt;
		rank = Rk;
		memset(rank, 0, n * sizeof(int));
		iota(root, root + n, 0);
	}

	int Find(int x) { return (x == root[x]) ? x : root[x] = Find(root[x]); }

	bool Union(int x, int y) {
		x = Find(x), y = Find(y);
		if (x == y) {
			return 0;
		}
		if (rank[x] > rank[y]) {
			swap(x, y);
		}
		root[x] = y;
		if (rank[x] == rank[y]) {
			rank[y]++;
		}
		return 1;
	}
};

class Solution {
   public:
	static bool containsCycle(vector<vector<char>>& grid) {
		const int r = grid.size(), c = grid[0].size(), sz = r * c;
		UnionFind G(sz);

		for (int i = 0; i < r - 1; i++) {
			int rIdx = i * c;
			for (int j = 0; j < c - 1; j++) {
				const int cur = rIdx + j, alpha = grid[i][j];
				if (grid[i + 1][j] == alpha && !G.Union(cur + c, cur)) {
					return 1;
				}
				if (grid[i][j + 1] == alpha && !G.Union(cur + 1, cur)) {
					return 1;
				}
			}
			const int cur = (i * c) + (c - 1), alpha = grid[i][c - 1];
			if (alpha == grid[i + 1][c - 1] && !G.Union(cur, cur + c)) {
				return 1;
			}
		}

		int rIdx = (r - 1) * c;
		auto& row = grid[r - 1];
		for (int j = 0; j < c - 1; j++) {
			const int cur = rIdx + j, alpha = row[j];
			if (row[j + 1] == alpha && !G.Union(cur + 1, cur)) {
				return 1;
			}
		}

		return 0;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)