class Solution {
   public:
	long long gridGame(vector<vector<int>>& grid) {
		int n = grid[0].size();
		long long topSum = 0, bottomSum = 0;
		long long currTopSum = 0, currBottomSum = 0, ans = LONG_LONG_MAX;

		for (int i = 0; i < n; i++) {
			topSum += grid[0][i];
			bottomSum += grid[1][i];
		}

		for (int i = 0; i < n; i++) {
			currTopSum += grid[0][i];
			ans = min(ans, max(topSum - currTopSum, currBottomSum));
			currBottomSum += grid[1][i];
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)