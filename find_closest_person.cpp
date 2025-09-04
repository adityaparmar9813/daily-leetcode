class Solution {
   public:
	int findClosest(int x, int y, int z) {
		int d1 = abs(z - x);
		int d2 = abs(z - y);

		return d1 == d2 ? 0 : d1 < d2 ? 1 : 2;
	}
};

// Time Complexity: O(1)
// Space Complexity: O(1)