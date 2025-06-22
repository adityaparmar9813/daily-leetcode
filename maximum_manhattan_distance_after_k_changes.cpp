class Solution {
   public:
	int maxDistance(string s, int k) {
		int x = 0, y = 0, ans = 0;
		int n = s.size();

		for (int i = 0; i < n; i++) {
			switch (s[i]) {
				case 'N':
					x++;
					break;
				case 'S':
					x--;
					break;
				case 'E':
					y++;
					break;
				case 'W':
					y--;
					break;
			}

			ans = max(ans, min(abs(x) + abs(y) + k * 2, i + 1));
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)