class Solution {
   public:
	int mirrorDistance(int n) {
		int rev = 0, num = n;

		while (num) {
			rev = rev * 10 + num % 10;
			num /= 10;
		}

		return abs(n - rev);
	}
};

// Time Complexity: O(1)
// Space Complexity: O(1)