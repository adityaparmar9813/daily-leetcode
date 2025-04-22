class Solution {
   public:
	const int MOD = 1e9 + 7;

	int idealArrays(int n, int maxValue) {
		vector<vector<int>> dp(maxValue + 1);

		int maxN = n + 100;
		vector<long> fact(maxN), invFact(maxN);
		fact[0] = invFact[0] = 1;
		for (int i = 1; i < maxN; ++i) {
			fact[i] = fact[i - 1] * i % MOD;
		}
		invFact[maxN - 1] = pow(fact[maxN - 1], MOD - 2);
		for (int i = maxN - 2; i > 0; --i) {
			invFact[i] = invFact[i + 1] * (i + 1) % MOD;
		}

		auto nCr = [&](int a, int b) -> int {
			if (b < 0 || b > a) return 0;
			return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
		};

		const int maxLen = 14;
		vector<vector<int>> f(maxLen + 1, vector<int>(maxValue + 1, 0));

		for (int i = 1; i <= maxValue; i++) {
			f[1][i] = 1;
		}

		for (int len = 2; len <= maxLen; ++len) {
			for (int i = 1; i <= maxValue; ++i) {
				for (int j = 2 * i; j <= maxValue; j += i) {
					f[len][j] = (f[len][j] + f[len - 1][i]) % MOD;
				}
			}
		}

		long res = 0;
		for (int len = 1; len <= maxLen; ++len) {
			long sum = 0;
			for (int i = 1; i <= maxValue; ++i) {
				sum = (sum + f[len][i]) % MOD;
			}
			res = (res + sum * nCr(n - 1, len - 1)) % MOD;
		}

		return res;
	}

	long pow(long base, int exp) {
		long result = 1;
		base %= MOD;
		while (exp > 0) {
			if (exp % 2 == 1) result = result * base % MOD;
			base = base * base % MOD;
			exp /= 2;
		}
		return result;
	}
};

// Time Complexity : O(n * log(n) + n * log(maxValue))
// Space Complexity : O(maxValue)