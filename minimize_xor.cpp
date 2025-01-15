class Solution {
   public:
	int minimizeXor(int num1, int num2) {
		int bits = __builtin_popcount(num2);
		int ans = 0;

		for (int i = 31; i >= 0 && bits > 0; i--) {
			if (num1 & (1 << i)) {
				ans |= (1 << i);
				bits--;
			}
		}
		for (int i = 0; i < 32 && bits > 0; i++) {
			if (!(ans & (1 << i))) {
				ans |= (1 << i);
				bits--;
			}
		}
		return ans;
	}
};

// Time Complexity: O(log(max(num1, num2)))
// Space Complexity: O(1)