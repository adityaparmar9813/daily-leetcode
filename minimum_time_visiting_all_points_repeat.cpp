class Solution {
   public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int ans = 0;

		for (int i = 1; i < points.size(); i++) {
			int x = abs(points[i][0] - points[i - 1][0]);
			int y = abs(points[i][1] - points[i - 1][1]);

			ans += max(x, y);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)