class Solution {
   public:
	int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
		vector<pair<int, int>> mp(m * n + 1);

		vector<int> rows(m, n), cols(n, m);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mp[mat[i][j]] = {i, j};
			}
		}

		for (int i = 0; i < arr.size(); i++) {
			int x = mp[arr[i]].first;
			int y = mp[arr[i]].second;

			rows[x]--;
			cols[y]--;

			if (rows[x] == 0 || cols[y] == 0) {
				return i;
			}
		}

		return arr.size();
	}
};

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)