class Solution {
   public:
	long long distributeCandies(int n, int limit) {
		long long ans = 0;

		for (int i = 0; i <= min(limit, n); i++) {
			ans += max(0, 2 * min(n - i, limit) - n + i + 1);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)