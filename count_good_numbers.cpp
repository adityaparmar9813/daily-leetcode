class Solution {
   public:
	const int MOD = 1e9 + 7;

	long long power(long long base, long long exp) {
		long long result = 1;
		base %= MOD;

		while (exp > 0) {
			if (exp % 2 == 1) {
				result = (result * base) % MOD;
			}

			base = (base * base) % MOD;
			exp /= 2;
		}

		return result;
	}

	int countGoodNumbers(long long n) {
		long long evenCount = (n + 1) / 2;
		long long oddCount = n / 2;

		long long evenPower = power(5, evenCount);
		long long oddPower = power(4, oddCount);

		return (evenPower * oddPower) % MOD;
	}
};

// Time Complexity : O(log n)
// Space Complexity : O(1)