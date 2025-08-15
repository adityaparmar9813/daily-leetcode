class Solution {
   public:
	bool isPowerOfFour(int n) {
		if (n == 4 || n == 1) {
			return true;
		}
		if (n % 4 != 0 || n == 0) {
			return false;
		}

		return isPowerOfFour(n / 4);
	}
};

// Time Complexity: O(log(n))
// Space Complexity: O(log(n))