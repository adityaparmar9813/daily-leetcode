class Solution {
  public:
	char findKthBit(int n, unsigned k) {
		if (k == 1) {
			return '0';
		}

		bool one = 1;

		while (k != bit_ceil(k)) {
			k = bit_ceil(k) - k;
			one = !one;
		}

		return '0' + one ^ (k == 1);
	}
};

// Time Complexity : O(log(n))
// Space Complexity : O(1)