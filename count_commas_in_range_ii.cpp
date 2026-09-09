class Solution {
   public:
	long long countCommas(long long n) {
		long long curr = 999;
		long long ans = 0;

		while (curr < n) {
			long long nextCurr = (curr + 1) * 1000;
			long long maxi = min(nextCurr - 1, n);
			ans += (maxi - curr) * (log10(curr + 1) / 3);
			curr = nextCurr - 1;
		}

		return ans;
	}
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)