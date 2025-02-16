class Solution {
   public:
	int n, az;
	bitset<21> visited = 0;
	vector<int> ans;

	bool dfs(int pos) {
		if (pos == az) {
			return visited.count() == n;
		}
		if (ans[pos] != 0) {
			return dfs(pos + 1);
		}

		for (int j = n; j >= 1; j--) {
			if (visited[j]) {
				continue;
			}
			int next_pos = (j > 1) ? pos + j : pos;

			if (next_pos >= az || ans[next_pos] != 0) {
				continue;
			}

			ans[pos] = ans[next_pos] = j;
			visited[j] = 1;

			if (dfs(pos + 1)) {
				return 1;
			}

			ans[pos] = ans[next_pos] = visited[j] = 0;
		}
		return 0;
	}

	vector<int> constructDistancedSequence(int n) {
		this->n = n;
		az = 2 * n - 1;
		ans.assign(az, 0);
		dfs(0);
		return ans;
	}
};

// Time Complexity: O(2 ^ n)
// Space Complexity: O(n)