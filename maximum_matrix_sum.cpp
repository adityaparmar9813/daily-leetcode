class Solution {
  public:
	long long maxMatrixSum(vector<vector<int>> &matrix) {
		int negCount = 0;
		long long sum = 0;
		int mini = 1e9;

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				sum += abs(matrix[i][j]);
				negCount += matrix[i][j] < 0;
				mini = min(mini, abs(matrix[i][j]));
			}
		}

		return negCount % 2 == 0 ? sum : sum - 2 * mini;
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(1)