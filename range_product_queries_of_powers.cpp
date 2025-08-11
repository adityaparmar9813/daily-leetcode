class Solution {
   public:
	const int MOD = 1e9 + 7;

	long long modPow(long long base, long long exp) {
		long long res = 1;
		while (exp > 0) {
			if (exp & 1) res = (res * base) % MOD;
			base = (base * base) % MOD;
			exp >>= 1;
		}
		return res;
	}

	vector<int> productQueries(int n, vector<vector<int>>& queries) {
		vector<long long> req;
		long long curr = 1;

		while (n > 0) {
			if (n & 1) req.push_back(curr);
			n >>= 1;
			curr <<= 1;
		}

		int size = req.size();
		vector<long long> prefix(size + 1, 1);

		for (int i = 0; i < size; i++) {
			prefix[i + 1] = (prefix[i] * req[i]) % MOD;
		}

		vector<int> ans(queries.size());
		for (int i = 0; i < queries.size(); i++) {
			int l = queries[i][0], r = queries[i][1];
			long long numerator = prefix[r + 1];
			long long denominator = prefix[l];
			long long inv = modPow(denominator, MOD - 2);
			ans[i] = (numerator * inv) % MOD;
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)