class Solution {
   public:
	int smallestNumber(int n, int t) {
		while (prodOfDigits(n) % t != 0) {
			n++;
		}
		return n;
	}

	int prodOfDigits(int n) {
		int rem = 0;
		int prod = 1;

		while (n > 0) {
			rem = n % 10;
			prod *= rem;
			n /= 10;
		}

		return prod;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)