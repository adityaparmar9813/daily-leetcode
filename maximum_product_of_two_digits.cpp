class Solution {
   public:
	int maxProduct(int n) {
		int big = -1, secondBig = -1;

		while (n != 0) {
			int r = n % 10;
			n /= 10;

			if (big == -1) {
				big = r;
			} else {
				secondBig = min(big, max(secondBig, r));
				big = max(big, r);
			}
		}

		return big * secondBig;
	}
};

// Time Complexity : O(log(n))
// Space Complexity : O(1)