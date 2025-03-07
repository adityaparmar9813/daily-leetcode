class Solution {
   public:
	vector<int> closestPrimes(int left, int right) {
		vector<bool> isPrime(right + 1, true);
		isPrime[1] = false;
		int prevPrime = -1;

		vector<int> ans = {-1, -1};
		int diff = 1e9;

		for (int i = 2; i <= right; i++) {
			if (!isPrime[i]) {
				continue;
			}

			if (prevPrime != -1 && i - prevPrime < diff) {
				ans = {prevPrime, i};
				diff = i - prevPrime;
			}

			for (int j = 2; j * i <= right; j++) {
				isPrime[i * j] = false;
			}

			if (i >= left) {
				prevPrime = i;
			}
		}

		return ans;
	}
};

// Time Complexity: O(right * log(log(right)))
// Space Complexity: O(right)