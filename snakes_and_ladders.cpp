class Solution {
   public:
	int snakesAndLadders(vector<vector<int>>& board) {
		int n = board.size();
		vector<pair<int, int>> mp(n * n + 1);
		bool flip = false;
		int curr = 1;

		for (int i = n - 1; i >= 0; i--) {
			if (!flip) {
				for (int j = 0; j < n; j++) {
					mp[curr++] = {i, j};
				}
			} else {
				for (int j = n - 1; j >= 0; j--) {
					mp[curr++] = {i, j};
				}
			}
			flip = !flip;
		}

		vector<bool> visited(n * n + 1, false);
		queue<pair<int, int>> q;
		q.push({1, 0});
		visited[1] = true;

		while (!q.empty()) {
			auto [pos, moves] = q.front();
			q.pop();
			if (pos == n * n) return moves;

			for (int d = 1; d <= 6 && pos + d <= n * n; d++) {
				int next = pos + d;
				auto [r, c] = mp[next];
				int dest = board[r][c] == -1 ? next : board[r][c];
				if (!visited[dest]) {
					visited[dest] = true;
					q.push({dest, moves + 1});
				}
			}
		}

		return -1;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)