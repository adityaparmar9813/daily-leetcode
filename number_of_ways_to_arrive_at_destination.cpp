class Solution {
   public:
	int countPaths(int n, vector<vector<int>>& roads) {
		const int kMod = 1e9 + 7;
		vector<vector<pair<int, int>>> adj(n);

		for (const auto& road : roads) {
			int u = road[0], v = road[1], time = road[2];
			adj[u].emplace_back(v, time);
			adj[v].emplace_back(u, time);
		}

		priority_queue<pair<long long, int>, vector<pair<long long, int>>,
		               greater<>>
		    pq;
		vector<long long> min_time(n, LLONG_MAX);
		vector<int> count(n, 0);

		min_time[0] = 0;
		count[0] = 1;
		pq.emplace(0, 0);

		while (!pq.empty()) {
			auto [time, curr] = pq.top();
			pq.pop();

			if (time > min_time[curr]) continue;

			for (const auto& [neigh, neigh_time] : adj[curr]) {
				if (time + neigh_time < min_time[neigh]) {
					min_time[neigh] = time + neigh_time;
					count[neigh] = count[curr] % kMod;
					pq.emplace(min_time[neigh], neigh);
				} else if (time + neigh_time == min_time[neigh]) {
					count[neigh] = (count[neigh] + count[curr]) % kMod;
				}
			}
		}

		return count[n - 1];
	}
};

// Time Complexity: O(n * log(n) + e)
// Space Complexity: O(n + e)