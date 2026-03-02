class Solution {
   public:
	int minSwaps(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<int> endingZero(n);

		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
				cnt++;
			}
			endingZero[i] = cnt;
		}

		int swaps = 0;

		for (int i = 0; i < n; i++) {
			int need = n - i - 1;
			int j = i;

			while (j < n && endingZero[j] < need) {
				j++;
			}

			if (j == n) return -1;

			while (j > i) {
				swap(endingZero[j], endingZero[j - 1]);
				swaps++;
				j--;
			}
		}

		return swaps;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n)