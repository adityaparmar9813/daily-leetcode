class Solution {
   public:
	const int INF = 1e9;
	int rows = 0, cols = 0, max_value = 0;

	void run_dp_transition(vector<vector<int>>& dp,
	                       vector<int>& best_teleport_cost,
	                       vector<vector<int>>& grid) {
		for (int r = rows - 1; r >= 0; --r) {
			for (int c = cols - 1; c >= 0; --c) {
				int walk_cost;

				if ((r == rows - 1) && (c == cols - 1)) {
					walk_cost = 0;
				} else {
					walk_cost = INF;
				}

				if (r + 1 < rows) {
					walk_cost = min(walk_cost, dp[r + 1][c] + grid[r + 1][c]);
				}

				if (c + 1 < cols) {
					walk_cost = min(walk_cost, dp[r][c + 1] + grid[r][c + 1]);
				}

				dp[r][c] = min(walk_cost, best_teleport_cost[grid[r][c]]);
			}
		}
	}

	vector<int> compute_best_teleport_cost(vector<vector<int>>& dp,
	                                       vector<vector<int>>& grid) {
		vector<int> teleport_cost(max_value + 1, INF);

		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < cols; ++c) {
				teleport_cost[grid[r][c]] =
				    min(teleport_cost[grid[r][c]], dp[r][c]);
			}
		}

		for (int v = 0; v <= max_value; ++v) {
			if (v > 0) {
				teleport_cost[v] = min(teleport_cost[v], teleport_cost[v - 1]);
			}
		}

		return teleport_cost;
	}

	int minCost(vector<vector<int>>& grid, int k) {
		rows = grid.size();
		cols = grid[0].size();

		for (auto& row : grid) {
			max_value = max(max_value, *max_element(row.begin(), row.end()));
		}

		vector<vector<int>> dp(rows, vector<int>(cols, INF));
		vector<int> best_teleport_cost(max_value + 1, INF);

		dp[rows - 1][cols - 1] = 0;

		for (int used = 0; used <= k; ++used) {
			run_dp_transition(dp, best_teleport_cost, grid);
			best_teleport_cost = compute_best_teleport_cost(dp, grid);
		}

		return dp[0][0];
	}
};

// Time Complexity: O(rows * cols * k)
// Space Complexity: O(rows * cols)