class Solution {
   public:
	long long INF = 1e18;
	unordered_map<string, int> index_of;
	vector<vector<long long>> min_cost;
	vector<long long> memo;
	string source, target;
	int n;

	long long compute_min_cost_from(int pos) {
		if (pos == n) {
			return 0;
		}

		if (memo[pos] != -1) {
			return memo[pos];
		}

		long long best = INF;

		if (source[pos] == target[pos]) {
			best = min(best, compute_min_cost_from(pos + 1));
		}

		for (auto& p1 : index_of) {
			const string& from = p1.first;
			int u = p1.second;
			int len = from.size();

			if (pos + len > n) {
				continue;
			}

			if (source.compare(pos, len, from) != 0) {
				continue;
			}

			for (auto& p2 : index_of) {
				const string& to = p2.first;
				int v = p2.second;

				if (target.compare(pos, len, to) != 0) {
					continue;
				}

				if (min_cost[u][v] == INF) {
					continue;
				}

				best = min(best,
				           min_cost[u][v] + compute_min_cost_from(pos + len));
			}
		}

		memo[pos] = best;
		return best;
	}

	long long minimumCost(string source_str, string target_str,
	                      vector<string>& original, vector<string>& changed,
	                      vector<int>& cost) {
		source = source_str;
		target = target_str;
		n = source.size();

		int id_count = 0;
		for (int i = 0; i < (int)original.size(); ++i) {
			if (!index_of.count(original[i])) {
				index_of[original[i]] = id_count++;
			}
			if (!index_of.count(changed[i])) {
				index_of[changed[i]] = id_count++;
			}
		}

		min_cost.assign(id_count, vector<long long>(id_count, INF));

		for (int i = 0; i < id_count; ++i) {
			min_cost[i][i] = 0;
		}

		for (int i = 0; i < (int)original.size(); ++i) {
			int u = index_of[original[i]];
			int v = index_of[changed[i]];
			min_cost[u][v] = min(min_cost[u][v], (long long)cost[i]);
		}

		for (int k = 0; k < id_count; ++k) {
			for (int i = 0; i < id_count; ++i) {
				for (int j = 0; j < id_count; ++j) {
					min_cost[i][j] =
					    min(min_cost[i][j], min_cost[i][k] + min_cost[k][j]);
				}
			}
		}

		memo.assign(n, -1);
		long long result = compute_min_cost_from(0);

		if (result >= INF) {
			return -1;
		}

		return result;
	}
};

// Time Complexity: O(n ^ 3)
// Space Complexity: O(n ^ 2)