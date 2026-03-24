class Solution {
   public:
	vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
		const int MOD = 12345;
		int n = grid.size(), m = grid[0].size();

		vector<int> arr;
		for (auto& row : grid) {
			for (int x : row) {
				arr.push_back(x % MOD);
			}
		}

		int N = arr.size();

		vector<int> prefix(N, 1), suffix(N, 1);

		for (int i = 1; i < N; i++) {
			prefix[i] = (1LL * prefix[i - 1] * arr[i - 1]) % MOD;
		}

		for (int i = N - 2; i >= 0; i--) {
			suffix[i] = (1LL * suffix[i + 1] * arr[i + 1]) % MOD;
		}

		vector<vector<int>> res(n, vector<int>(m));
		int idx = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = (1LL * prefix[idx] * suffix[idx]) % MOD;
				idx++;
			}
		}

		return res;
	}
};

// Time Complexity: O(N)
// Space Complexity: O(N)