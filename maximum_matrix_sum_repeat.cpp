class Solution {
   public:
	long long maxMatrixSum(vector<vector<int>>& matrix) {
		bool oddNegCount = false;
		int n = matrix.size(), smallest = 1e9;
		long long ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] < 0) {
					oddNegCount = !oddNegCount;
				}
				smallest = min(smallest, abs(matrix[i][j]));
				ans += abs(matrix[i][j]);
			}
		}

		if (oddNegCount) {
			ans -= (2 * abs(smallest));
		}

		return ans;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(1)