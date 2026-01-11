class Solution {
   public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size(), n = matrix[0].size(), ans = 0;
		vector<vector<int>> prefix(m, vector<int>(n));

		for (int i = 0; i < m; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (matrix[i][j] == '0') {
					prefix[i][j] = 0;
				} else {
					prefix[i][j] = j == n - 1 ? 1 : prefix[i][j + 1] + 1;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '0') {
					continue;
				}

				int minOnes = n;

				for (int k = i; k < m; k++) {
					if (matrix[k][j] == '0') {
						break;
					}

					minOnes = min(minOnes, prefix[k][j]);
					ans = max(ans, (k - i + 1) * minOnes);
				}
			}
			cout << endl;
		}

		return ans;
	}
};

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)