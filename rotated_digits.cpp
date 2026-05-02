class Solution {
   public:
	int rotatedDigits(int n) {
		int ans = 0;

		for (int i = 1; i <= n; i++) {
			int num = i;
			bool valid = true, changed = false;

			while (num > 0) {
				int r = num % 10;
				num /= 10;

				if (r == 0 || r == 1 || r == 8) {
					continue;
				} else if (r == 2 || r == 5 || r == 6 || r == 9) {
					changed = true;
				} else {
					valid = false;
					break;
				}
			}

			if (valid && changed) {
				ans++;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)