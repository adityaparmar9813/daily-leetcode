class Solution {
   public:
	long long coloredCells(int n) {
		if (n-- == 1) {
			return 1;
		}

		return 1 + (n * 1ll * (2 * 4 + (n - 1) * 1ll * 4)) / 2;
	}
};

// Time Complexity: O(1)
// Space Complexity: O(1)