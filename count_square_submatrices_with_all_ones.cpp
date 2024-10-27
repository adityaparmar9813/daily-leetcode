class Solution {
  public:
	int countSquares(vector<vector<int>> &matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int total_count = 0;

		for (int size = 1; size <= 300; size++) {
			if (size > rows || size > cols)
				break;

			for (int i = 0; i <= rows - size; i++) {
				for (int j = 0; j <= cols - size; j++) {
					bool is_valid = true;

					for (int r = i; r < i + size; r++) {
						for (int c = j; c < j + size; c++) {
							if (matrix[r][c] == 0) {
								is_valid = false;
								break;
							}
						}
						if (!is_valid) {
							break;
						}
					}
					if (is_valid) {
						total_count++;
					}
				}
			}
		}
		return total_count;
	}
};

// Time Complexity: O(n ^ 3)
// Space Complexity: O(1)