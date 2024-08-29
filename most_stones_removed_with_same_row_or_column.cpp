class UnionFind {
	vector<int> root, Size;

  public:
	int merge;
	UnionFind(int N) : root(N), Size(N, 1), merge(0) {
		iota(root.begin(), root.end(), 0);
	}

	int Find(int x) {
		if (x == root[x])
			return x;
		return root[x] = Find(root[x]);
	}

	bool Union(int x, int y) {
		x = Find(x), y = Find(y);

		if (x == y)
			return 0;

		if (Size[x] > Size[y]) {
			Size[x] += Size[y];
			root[y] = x;
		} else {
			Size[y] += Size[x];
			root[x] = y;
		}
		merge++;
		return 1;
	}
};

class Solution {
  public:
	int removeStones(vector<vector<int>> &stones) {
		const int n = stones.size(), M = 10001, N = 2 * M + 1;
		UnionFind G(N);
		bitset<20003> count = 0;

		for (int idx = 0; idx < n; idx++) {
			const int i = stones[idx][0], j = stones[idx][1];
			G.Union(i, M + j);
			count[i] = count[M + j] = 1;
		}
		return n - count.count() + G.merge;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)