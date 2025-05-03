class Solution {
   public:
	int check(int x, vector<int>& tops, vector<int>& bottoms) {
		int n = tops.size();
		int rotationsTop = 0, rotationsBottom = 0;

		for (int i = 0; i < n; i++) {
			if (tops[i] != x && bottoms[i] != x) {
				return -1;
			} else if (tops[i] != x) {
				rotationsTop++;
			} else if (bottoms[i] != x) {
				rotationsBottom++;
			}
		}

		return min(rotationsTop, rotationsBottom);
	}

	int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
		int rotations = check(tops[0], tops, bottoms);

		if (rotations != -1 || tops[0] == bottoms[0]) {
			return rotations;
		}

		return check(bottoms[0], tops, bottoms);
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)