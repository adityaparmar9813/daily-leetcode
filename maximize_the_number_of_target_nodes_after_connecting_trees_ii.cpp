class Solution {
   public:
	vector<vector<int>> adj1, adj2;
	vector<int> depth1, depth2;

	void dfs1(int u, int p) {
		for (int v : adj1[u]) {
			if (v == p) continue;
			depth1[v] = depth1[u] + 1;
			dfs1(v, u);
		}
	}

	void dfs2(int u, int p) {
		for (int v : adj2[u]) {
			if (v == p) continue;
			depth2[v] = depth2[u] + 1;
			dfs2(v, u);
		}
	}

	vector<int> maxTargetNodes(vector<vector<int>>& edges1,
	                           vector<vector<int>>& edges2) {
		int n = edges1.size() + 1, m = edges2.size() + 1;

		adj1.resize(n);
		for (auto& e : edges1) {
			adj1[e[0]].push_back(e[1]);
			adj1[e[1]].push_back(e[0]);
		}

		depth1.resize(n);
		dfs1(0, -1);

		int even1 = 0, odd1 = 0;
		for (int i = 0; i < n; i++) {
			if (depth1[i] % 2 == 0)
				even1++;
			else
				odd1++;
		}

		adj2.resize(m);
		for (auto& e : edges2) {
			adj2[e[0]].push_back(e[1]);
			adj2[e[1]].push_back(e[0]);
		}

		depth2.resize(m);
		dfs2(0, -1);

		int even2 = 0, odd2 = 0;
		for (int i = 0; i < m; i++) {
			if (depth2[i] % 2 == 0)
				even2++;
			else
				odd2++;
		}

		int best2 = max(even2, odd2);

		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			int ev1 = (depth1[i] % 2 == 0 ? even1 : odd1);
			res[i] = ev1 + best2;
		}

		return res;
	}
};

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)