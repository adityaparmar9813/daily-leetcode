class Solution {
   public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
	                                 vector<vector<int>>& queries) {
		vector<bitset<100>> prereq(n);
		vector<vector<int>> adj(n);
		vector<int> inDegree(n, 0);

		for (auto& edge : prerequisites) {
			int a = edge[0], b = edge[1];
			adj[a].push_back(b);
			prereq[b].set(a);
			inDegree[b]++;
		}

		queue<int> q;

		for (int i = 0; i < n; ++i) {
			if (inDegree[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : adj[u]) {
				prereq[v] |= prereq[u];

				if (--inDegree[v] == 0) {
					q.push(v);
				}
			}
		}

		vector<bool> ans;
		ans.reserve(queries.size());

		for (auto& qry : queries) {
			int u = qry[0], v = qry[1];
			ans.push_back(prereq[v][u]);
		}

		return ans;
	}
};

// Time Complexity : O(n + m)
// Space Complexity : O(n + m)