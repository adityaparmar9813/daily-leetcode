class Solution {
  public:
	int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
		unordered_map<string, int> patternCount;
		int maxRows = 0;

		for (const auto &row : matrix) {
			string pattern = "";
			string complement = "";

			for (int cell : row) {
				pattern += (cell == 0 ? '0' : '1');
				complement += (cell == 0 ? '1' : '0');
			}

			patternCount[pattern]++;
			maxRows = max(maxRows, patternCount[pattern]);

			patternCount[complement]++;
			maxRows = max(maxRows, patternCount[complement]);
		}

		return maxRows;
	}
};

// Time Complexity: O(m * n)
// Space Complexity: O(m)