class Solution {
   public:
	int dist(int u, int k, vector<vector<int>>& adj, vector<vector<int>>& dp) {
		if (k < 0) {
			return 0;
		}
		if (dp[u][k] != -1) {
			return dp[u][k];
		}

		queue<pair<int, int>> q;
		vector<bool> seen(adj.size(), false);
		q.push({u, 0});
		seen[u] = true;
		int count = 0;

		while (!q.empty()) {
			auto [node, d] = q.front();
			q.pop();

			if (d > k) {
				break;
			}
			count++;
			if (d == k) {
				continue;
			}

			for (int node : adj[node]) {
				if (!seen[node]) {
					seen[node] = true;
					q.push({node, d + 1});
				}
			}
		}

		return dp[u][k] = count;
	}

	vector<vector<int>> buildTree(vector<vector<int>>& edges, int size) {
		vector<vector<int>> tree(size);
		for (const auto& edge : edges) {
			tree[edge[0]].push_back(edge[1]);
			tree[edge[1]].push_back(edge[0]);
		}
		return tree;
	}

	vector<int> buildRes(vector<vector<int>>& tree, int size, int k,
	                     vector<vector<int>>& dp) {
		vector<int> res(size);
		for (int i = 0; i < size; i++) {
			res[i] = dist(i, k, tree, dp);
		}
		return res;
	}

	vector<int> maxTargetNodes(vector<vector<int>>& edges1,
	                           vector<vector<int>>& edges2, int k) {
		int n = edges1.size() + 1, m = edges2.size() + 1;
		auto tree1 = buildTree(edges1, n);
		auto tree2 = buildTree(edges2, m);

		vector<vector<int>> dp1(n, vector<int>(k + 1, -1));
		vector<vector<int>> dp2(m, vector<int>(k, -1));

		auto res1 = buildRes(tree1, n, k, dp1);
		auto res2 = buildRes(tree2, m, k - 1, dp2);
		int maxi = *max_element(res2.begin(), res2.end());

		for (int i = 0; i < n; i++) {
			res1[i] += maxi;
		}

		return res1;
	}
};

// Time Complexity : O(n + m)
// Space Complexity : O(n + m)