class Solution {
   public:
	int minTimeToReach(vector<vector<int>>& moveTime) {
		using ll = long long;
		int m = moveTime.size(), n = moveTime[0].size();
		priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
		pq.push({0, 0, 0, 1});
		vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		vector<vector<bool>> visited(m, vector<bool>(n, false));

		while (!pq.empty()) {
			auto top = pq.top();
			pq.pop();
			ll time = top[0], x = top[1], y = top[2], inc = top[3];

			if (visited[x][y]) {
				continue;
			}
			visited[x][y] = true;

			if (x == m - 1 && y == n - 1) {
				return time;
			}

			for (const auto& d : dir) {
				int nx = x + d.first, ny = y + d.second;

				if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
					continue;
				}

				pq.push(
				    {max(time, (ll)moveTime[nx][ny]) + inc, nx, ny, 3 - inc});
			}
		}

		return -1;
	}
};

// Time Complexity: O(m * n * log(m * n))
// Space Complexity: O(m * n)