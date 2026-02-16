class Solution {
   public:
	int reverseBits(int n) {
		int curr = 31, res = 0;

		while (curr >= 0) {
			res += (n % 2) * pow(2, curr--);
			n >>= 1;
		}

		return res;
	}
};

// Time Complexity: O(1)
// Space Complexity: O(1)