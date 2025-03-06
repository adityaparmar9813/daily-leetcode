class Solution {
   public:
	vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<int> count(n * n, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				count[grid[i][j] - 1]++;
			}
		}

		vector<int> ans(2);

		for (int i = 0; i < n * n; i++) {
			if (count[i] == 2) {
				ans[0] = i + 1;
			}
			if (count[i] == 0) {
				ans[1] = i + 1;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)