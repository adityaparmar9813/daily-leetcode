class Solution {
   public:
	int furthestDistanceFromOrigin(string moves) {
		int l = 0, r = 0;

		for (char move : moves) {
			if (move == 'L') {
				l++;
			} else if (move == 'R') {
				r++;
			}
		}

		return max(l, r) + (moves.size() - l - r) - min(l, r);
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)