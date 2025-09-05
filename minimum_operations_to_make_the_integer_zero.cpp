class Solution {
   public:
	int makeTheIntegerZero(int num1, int num2) {
		for (int i = 1; i <= 60; i++) {
			long long remain = num1 - 1LL * i * num2;

			if (remain < i) {
				continue;
			}

			int ones = 0;
			long long temp = remain;

			while (temp > 0) {
				ones += (temp & 1);
				temp >>= 1;
			}

			if (ones <= i) {
				return i;
			}
		}

		return -1;
	}
};

// Time Complexity: O(1)
// Space Complexity: O(1)