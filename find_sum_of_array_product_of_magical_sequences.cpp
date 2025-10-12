using int64 = long long;
const int MOD = 1e9 + 7;

int addmod(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

int64 mulmod(int64 a, int64 b) { return (a * b) % MOD; }

int powmod(int64 a, int64 e) {
	int64 r = 1 % MOD;
	a %= MOD;
	while (e) {
		if (e & 1) {
			r = (r * a) % MOD;
		}
		a = (a * a) % MOD;
		e >>= 1;
	}
	return (int)r;
}

class Solution {
   public:
	int magicalSum(int m, int k, vector<int>& nums) {
		int n = (int)nums.size();

		vector<int64> fact(m + 1, 1), invfact(m + 1, 1);
		for (int i = 1; i <= m; i++) {
			fact[i] = fact[i - 1] * i % MOD;
		}
		invfact[m] = powmod(fact[m], MOD - 2);
		for (int i = m; i > 0; i--) {
			invfact[i - 1] = invfact[i] * i % MOD;
		}

		vector<vector<int>> pow_nums(n, vector<int>(m + 1, 1));
		for (int i = 0; i < n; i++) {
			pow_nums[i][0] = 1;
			for (int c = 1; c <= m; c++) {
				pow_nums[i][c] =
				    (int)((int64)pow_nums[i][c - 1] * (nums[i] % MOD) % MOD);
			}
		}

		int extra = 6;
		int total_bits = n + extra;

		auto make3d = [&](int A, int B, int C) {
			return vector<vector<vector<int>>>(
			    A, vector<vector<int>>(B, vector<int>(C, 0)));
		};

		auto dp = make3d(m + 1, m + 1, k + 1);
		dp[0][0][0] = 1;

		for (int pos = 0; pos < total_bits; ++pos) {
			auto ndp = make3d(m + 1, m + 1, k + 1);
			for (int used = 0; used <= m; ++used) {
				for (int carry = 0; carry <= m; ++carry) {
					for (int onesCount = 0; onesCount <= k; ++onesCount) {
						int cur = dp[used][carry][onesCount];
						if (!cur) {
							continue;
						}

						int maxc = (pos < n) ? (m - used) : 0;
						for (int c = 0; c <= maxc; ++c) {
							int total = carry + c;
							int bit = total & 1;
							int carry_next = total >> 1;
							if (carry_next > m) {
								continue;
							}

							int newOnes = onesCount + bit;
							if (newOnes > k) {
								continue;
							}

							int64 mult = cur;
							if (c > 0) {
								if (pos < n) {
									mult = (mult * pow_nums[pos][c]) % MOD;
								}
								mult = (mult * invfact[c]) % MOD;
							}

							ndp[used + c][carry_next][newOnes] = addmod(
							    ndp[used + c][carry_next][newOnes], (int)mult);
						}
					}
				}
			}
			dp.swap(ndp);
		}

		int ans_unordered = dp[m][0][k];
		int64 ans = (int64)ans_unordered * fact[m] % MOD;
		return (int)ans;
	}
};

// Time Complexity : O(n * m)
// Space Complexity : O(m ^ 3)