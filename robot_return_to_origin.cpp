class Solution {
   public:
	bool judgeCircle(string moves) {
		int x = 0, y = 0;

		for (const char& move : moves) {
			switch (move) {
				case 'L':
					x--;
					break;
				case 'R':
					x++;
					break;
				case 'U':
					y++;
					break;
				case 'D':
					y--;
			}
		}

		return x == 0 && y == 0;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)