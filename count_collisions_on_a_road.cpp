class Solution {
   public:
	int countCollisions(string directions) {
		int n = directions.size(), l = 0, r = n - 1, collisions = 0;

		while (l < n && directions[l] == 'L') {
			l++;
		}
		while (r >= 0 && directions[r] == 'R') {
			r--;
		}

		for (int i = l; i <= r; i++) {
			if (directions[i] != 'S') {
				collisions++;
			}
		}

		return collisions;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)