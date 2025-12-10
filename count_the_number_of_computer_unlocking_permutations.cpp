class Solution {
   public:
	const int MOD = 1e9 + 7;

	long long factorial(long long n) {
		long long res = 1;

		for (long long i = 1; i <= n; i++) {
			res = (res * i) % MOD;
		}
		return res;
	}

	int countPermutations(vector<int>& complexity) {
		int n = complexity.size();
		long long mn = complexity[0];

		for (int i = 1; i < n; i++) {
			if (mn >= complexity[i]) {
				return 0;
			}
			mn = min(mn, (long long)complexity[i]);
		}
		return factorial(n - 1);
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)