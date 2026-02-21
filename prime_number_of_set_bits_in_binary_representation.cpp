class Solution {
   public:
	int countPrimeSetBits(int left, int right) {
		int count = 0;
		unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

		for (int i = left; i <= right; i++) {
			int num = i, bits = 0;

			while (num) {
				if (num & 1) {
					bits++;
				}
				num >>= 1;
			}

			if (primes.find(bits) != primes.end()) {
				count++;
			}
		}
		return count;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)