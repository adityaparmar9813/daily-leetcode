class Solution {
  public:
	long long maxPoints(vector<vector<int>> &points) {
		int n = points[0].size();
		long long currMax;
		vector<long long> maxPoints(n), dp(n);

		for (vector<int> row : points) {
			currMax = 0;
			for (int j = n - 1; j >= 0; j--) {
				currMax = max(currMax, maxPoints[j]);
				dp[j] = currMax--;
			}

			currMax = 0;
			for (int j = 0; j < n; j++) {
				currMax = max(currMax, maxPoints[j]);
				maxPoints[j] = max(currMax--, dp[j]) + row[j];
			}
		}

		return *max_element(maxPoints.begin(), maxPoints.end());
	}
};

// Time Complexity : O(n * m)
// Space Complexity : O(n)