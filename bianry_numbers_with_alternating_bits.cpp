class Solution {
   public:
	bool hasAlternatingBits(int n) {
		bool prev = (n % 2 == 0);

		while (n != 0) {
			if (prev == (n % 2)) {
				return false;
			}
			prev = n % 2;
			n /= 2;
		}

		return true;
	}
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)