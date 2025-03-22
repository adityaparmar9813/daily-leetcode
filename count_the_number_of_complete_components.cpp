class UnionFind {
	vector<int> parent;

   public:
	UnionFind(int n) {
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unite(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY) {
			parent[rootX] = rootY;
		}
	}
};

class Solution {
   public:
	int countCompleteComponents(int n, vector<vector<int>>& edges) {
		UnionFind dsu(n);
		unordered_map<int, int> componentSize, edgeCount;
		unordered_map<int, unordered_set<int>> adj;

		for (const auto& edge : edges) {
			dsu.unite(edge[0], edge[1]);
			adj[edge[0]].insert(edge[1]);
			adj[edge[1]].insert(edge[0]);
		}

		for (int i = 0; i < n; i++) {
			componentSize[dsu.find(i)]++;
		}

		for (int i = 0; i < n; i++) {
			edgeCount[dsu.find(i)] += adj[i].size();
		}

		int cyclicComponents = 0;
		for (const auto& [root, size] : componentSize) {
			if (edgeCount[root] / 2 == (size * (size - 1)) / 2) {
				cyclicComponents++;
			}
		}

		return cyclicComponents;
	}
};

// Time Complexity : O(n + e)
// Space Complexity : O(n + e)