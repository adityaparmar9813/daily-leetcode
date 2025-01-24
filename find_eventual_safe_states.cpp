class Solution {
   public:
	bool dfs(int index, vector<int>& safe, vector<vector<int>>& graph) {
		if (safe[index] != -1) {
			return safe[index];
		}

		safe[index] = 0;

		for (int neighbor : graph[index]) {
			if (!dfs(neighbor, safe, graph)) {
				return false;
			}
		}

		safe[index] = 1;
		return true;
	}

	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> safe(n, -1);
		vector<int> ans;

		for (int i = 0; i < n; i++) {
			dfs(i, safe, graph);
		}

		for (int i = 0; i < n; i++) {
			if (safe[i]) {
				ans.push_back(i);
			}
		}

		return ans;
	}
};

// Time Complexity : O(V + E)
// Space Complexity : O(V)