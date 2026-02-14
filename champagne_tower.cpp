class Solution {
   public:
	double champagneTower(int poured, int query_row, int query_glass) {
		vector<double> currRow = {(double)poured};

		while (query_row--) {
			vector<double> nextRow((int)currRow.size() + 1, 0.0);

			for (auto i = 0; i < (int)currRow.size(); i++) {
				double overflow = max(0.0, currRow[i] - 1.0);

				nextRow[i] += overflow / 2.0;
				nextRow[i + 1] += overflow / 2.0;
			}

			swap(currRow, nextRow);
		}

		return min(1.0, currRow[query_glass]);
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n)