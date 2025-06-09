class Solution {
   public:
	int solve(long long current, long long n, long long k) {
		if (k == 0) {
			return (int)(current / 10);
		}

		for (long long i = max(current, 1LL); i < current + 10; i++) {
			long long count = numOfChildren(i, i + 1, n);

			if (count >= k) {
				return solve(i * 10, n, k - 1);
			}

			k -= count;
		}

		return -1;
	}

	long long numOfChildren(long long current, long long neighbour,
	                        long long n) {
		if (neighbour > n && current > n) {
			return 0;
		}

		if (neighbour > n) {
			return n - current + 1;
		}

		return neighbour - current +
		       numOfChildren(current * 10, neighbour * 10, n);
	}

	int findKthNumber(int n, int k) { return solve(0, n, k); }
};

// Time Complexity: O(log(n) * log(k))
// Space Complexity: O(1)