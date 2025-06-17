class Solution {
   public:
	const int mod = 1e9 + 7;
	using ll = long long;

	int binpow(int a, int b) {
		int ans = 1;

		while (b) {
			if (b % 2) {
				ans = (1LL * a * ans) % mod;
			}

			b /= 2;
			a = (1LL * a * a) % mod;
		}
		return ans;
	}

	int NCR(int n, int r) {
		r = min(r, n - r);
		int ans = 1;
		int rfac = 1;

		for (int i = 0; i < r; i++) {
			ans = (1LL * ans * (n - i)) % mod;
			rfac = (1LL * rfac * (i + 1)) % mod;
		}
		ans = (1LL * ans * binpow(rfac, mod - 2)) % mod;
		return ans;
	}

	int countGoodArrays(int n, int m, int k) {
		int ans = m;
		ans = (1LL * ans * binpow(m - 1, n - k - 1)) % mod;
		ans = (1LL * ans * NCR(n - 1, k)) % mod;
		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)