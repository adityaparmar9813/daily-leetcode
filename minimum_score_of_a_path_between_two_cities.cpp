class Solution {
   public:
	int minScore(int n, vector<vector<int>>& roads) {
		vector<vector<pair<int, int>>> adj(n + 1);

		for (auto it : roads) {
			adj[it[0]].push_back({it[1], it[2]});
			adj[it[1]].push_back({it[0], it[2]});
		}

		int ans = INT_MAX;
		vector<bool> visited(n + 1, false);

		queue<int> q;
		q.push(1);
		visited[1] = true;

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (auto it : adj[node]) {
				ans = min(ans, it.second);

				if (!visited[it.first]) {
					visited[it.first] = true;
					q.push(it.first);
				}
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)