class Solution {
   public:
	vector<pair<unsigned, int>> adj[50000];
	unsigned dist[50000];

	void build_adj(int n, vector<vector<int>>& edges) {
		for (int i = 0; i < n; i++) {
			adj[i].clear();
		}

		for (auto& e : edges) {
			unsigned w = e[2];
			int u = e[0], v = e[1];
			adj[u].push_back({w, v});
			adj[v].push_back({2 * w, u});
		}
	}

	int minCost(int n, vector<vector<int>>& edges) {
		build_adj(n, edges);

		priority_queue<pair<unsigned, int>, vector<pair<unsigned, int>>,
		               greater<>>
		    pq;

		fill(dist, dist + n, UINT_MAX);

		dist[0] = 0;
		pq.push({0, 0});

		while (!pq.empty()) {
			auto [d, u] = pq.top();
			pq.pop();

			if (d != dist[u]) {
				continue;
			}
			if (u == n - 1) {
				return d;
			}

			for (auto& [w, v] : adj[u]) {
				unsigned d2 = d + w;
				if (d2 < dist[v]) {
					dist[v] = d2;
					pq.push({d2, v});
				}
			}
		}
		return -1;
	}
};

// Time Complexiy: O(n ^ 2)
// Space Complexity: O(n ^ 2)