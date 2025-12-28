class Solution {
   public:
	int countNegatives(vector<vector<int>>& grid) {
		int ans = 0, m = grid.size(), n = grid[0].size();
		int i = 0, j = n - 1;

		while (i < m && j >= 0) {
			if (grid[i][j] < 0) {
				ans += (m - i);
				j--;
			} else {
				i++;
			}
		}

		return ans;
	}
};

// Time Complexity : O(m + n)
// Space Complexity : O(1)