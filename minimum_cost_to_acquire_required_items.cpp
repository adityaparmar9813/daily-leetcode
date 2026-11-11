class Solution {
   public:
	long long minimumCost(int cost1, int cost2, int costBoth, int need1,
	                      int need2) {
		long long min = fmin(need1, need2);
		long long max = fmax(need1, need2);
		long long ans = (long long)need1 * cost1 + (long long)need2 * cost2;

		ans = fmin(ans, (long long)min * costBoth +
		                    (long long)(need1 - min) * cost1 +
		                    (long long)(need2 - min) * cost2);
		ans = fmin(ans, (long long)max * costBoth);

		return ans;
	}
};

// Time Complexity : O(1)
// Space Complexity : O(1)