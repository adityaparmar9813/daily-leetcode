class UnionFind {
	int n;
	vector<int> parent;

   public:
	UnionFind(int n) {
		this->n = n;

		for (int i = 0; i < n; i++) {
			parent.push_back(i);
		}
	}

	int Find(int u) {
		while (parent[u] != u) {
			u = parent[u];
		}
		return u;
	}

	void Union(int u, int v) {
		u = this->Find(u);
		v = this->Find(v);

		if (u != v) {
			parent[v] = u;
		}
	}
};

class Solution {
   public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		UnionFind graph(n + 1);

		for (int i = 0; i < n; i++) {
			int u = edges[i][0];
			int v = edges[i][1];

			if (graph.Find(u) == graph.Find(v)) {
				return {u, v};
			} else {
				graph.Union(u, v);
			}
		}
		return {};
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)