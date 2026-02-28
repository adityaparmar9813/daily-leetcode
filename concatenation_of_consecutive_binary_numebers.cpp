class Solution {
   public:
	const int MOD = 1e9 + 7;

	int concatenatedBinary(int n) {
		int mul = 1, ans = 0;

		for (int i = n; i > 0; i--) {
			int num = i;

			while (num != 0) {
				ans = (ans + (num % 2) * mul) % MOD;
				mul = (mul * 2) % MOD;
				num /= 2;
			}
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)