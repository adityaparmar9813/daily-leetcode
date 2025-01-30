class Solution {
	vector<int> color;
	vector<vector<int>> adj;
	int n;

	bool isBipartite(int node, int c, vector<int>& component) {
		color[node] = c;
		component.push_back(node);

		for (int nbr : adj[node]) {
			if (color[nbr] == c) return false;
			if (color[nbr] == -1 && !isBipartite(nbr, 1 - c, component)) {
				return false;
			}
		}
		return true;
	}

	int maxGroupsInComponent(const vector<int>& component) {
		int maxDepth = 0;

		for (int start : component) {
			vector<int> depth(n, -1);
			queue<int> q;
			q.push(start);
			depth[start] = 0;

			while (!q.empty()) {
				int node = q.front();
				q.pop();

				for (int nbr : adj[node]) {
					if (depth[nbr] == -1) {
						depth[nbr] = depth[node] + 1;
						maxDepth = max(maxDepth, depth[nbr]);
						q.push(nbr);
					}
				}
			}
		}
		return maxDepth + 1;
	}

   public:
	int magnificentSets(int n, vector<vector<int>>& edges) {
		int total = 0;
		this->n = n;
		color.assign(n, -1);
		adj.resize(n);

		for (auto& e : edges) {
			int u = e[0] - 1, v = e[1] - 1;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<vector<int>> components;

		for (int i = 0; i < n; ++i) {
			if (color[i] == -1) {
				components.emplace_back();

				if (!isBipartite(i, 0, components.back())) {
					return -1;
				}
			}
		}

		for (auto& comp : components) {
			total += maxGroupsInComponent(comp);
		}

		return total;
	}
};

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)