class Solution {
   public:
	void dfs(int u, const vector<int>& present, const vector<int>& future,
	         const vector<vector<int>>& tree, vector<vector<vector<int>>>& dp,
	         int budget) {
		vector<pair<vector<int>, vector<int>>> childDPs;

		for (int v : tree[u]) {
			dfs(v, present, future, tree, dp, budget);
			childDPs.emplace_back(dp[v][0], dp[v][1]);
		}

		for (int parentBought = 0; parentBought <= 1; ++parentBought) {
			int price = parentBought ? present[u] / 2 : present[u];
			int profit = future[u] - price;

			vector<int> curr(budget + 1, 0);

			vector<int> base(budget + 1, 0);
			for (const auto& child : childDPs) {
				vector<int> next(budget + 1, 0);
				for (int b1 = 0; b1 <= budget; ++b1) {
					if (base[b1] == 0 && b1 != 0) continue;
					for (int b2 = 0; b1 + b2 <= budget; ++b2) {
						next[b1 + b2] =
						    max(next[b1 + b2], base[b1] + child.first[b2]);
					}
				}
				base = move(next);
			}

			for (int b = 0; b <= budget; ++b) {
				curr[b] = max(curr[b], base[b]);
			}

			if (price <= budget) {
				vector<int> baseBuy(budget + 1, 0);
				for (const auto& child : childDPs) {
					vector<int> next(budget + 1, 0);
					for (int b1 = 0; b1 <= budget; ++b1) {
						if (baseBuy[b1] == 0 && b1 != 0) continue;
						for (int b2 = 0; b1 + b2 <= budget; ++b2) {
							next[b1 + b2] = max(next[b1 + b2],
							                    baseBuy[b1] + child.second[b2]);
						}
					}
					baseBuy = move(next);
				}

				for (int b = price; b <= budget; ++b) {
					curr[b] = max(curr[b], baseBuy[b - price] + profit);
				}
			}

			dp[u][parentBought] = move(curr);
		}
	}

	int maxProfit(int n, vector<int>& present, vector<int>& future,
	              vector<vector<int>>& hierarchy, int budget) {
		vector<vector<int>> tree(n);
		for (const auto& edge : hierarchy) {
			tree[edge[0] - 1].push_back(edge[1] - 1);
		}

		vector<vector<vector<int>>> dp(
		    n, vector<vector<int>>(2, vector<int>(budget + 1, 0)));

		dfs(0, present, future, tree, dp, budget);

		int ans = 0;
		for (int b = 0; b <= budget; ++b) {
			ans = max(ans, dp[0][0][b]);
		}
		return ans;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)