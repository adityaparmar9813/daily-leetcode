class Solution {
  public:
	int countUnguarded(int n, int m, vector<vector<int>> &guards,
					   vector<vector<int>> &walls) {
		vector<vector<int>> v(n, vector<int>(m, 0));

		for (auto it : walls) {
			v[it[0]][it[1]] = -1;
		}

		queue<vector<int>> q;

		vector<vector<vector<int>>> vis(
			n, vector<vector<int>>(m, vector<int>(5, -1)));

		vector<int> dir = {-1, 0, 1, 0, -1};

		for (auto it : guards) {
			v[it[0]][it[1]] = 1;

			for (int i = 0; i < dir.size() - 1; i++) {
				vis[it[0]][it[1]][i] = i;
				int next_i = it[0] + dir[i];
				int next_j = it[1] + dir[i + 1];

				if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m &&
					v[next_i][next_j] != -1 && vis[next_i][next_j][i] == -1) {
					q.push({next_i, next_j, i});
					v[next_i][next_j] = 1;
					vis[next_i][next_j][i] = i;
				}
			}
		}

		while (!q.empty()) {
			auto front = q.front();
			q.pop();
			int i = front[2];
			int next_i = front[0] + dir[i];
			int next_j = front[1] + dir[i + 1];

			if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m &&
				v[next_i][next_j] != -1 && vis[next_i][next_j][i] == -1) {
				q.push({next_i, next_j, i});
				v[next_i][next_j] = 1;
				vis[next_i][next_j][i] = i;
			}
		}

		int count = 0;
		for (auto it : v) {
			for (auto i : it) {
				if (i == 0) {
					++count;
				}
			}
		}

		return count;
	}
};

// Time Complexity : O(n * m)
// Space Complexity : O(n * m)