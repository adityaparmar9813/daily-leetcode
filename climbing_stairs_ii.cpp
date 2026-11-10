class Solution {
   public:
	int climbStairs(int n, vector<int>& costs) {
		costs.insert(costs.begin(), 0);
		vector<int> memo(n + 1);

		auto climb = [&](this auto&& climb, int i) -> int {
			if (i > n) {
				return INT_MAX / 2;
			}
			if (i == n) {
				return costs[n];
			}
			if (!memo[i]) {
				memo[i] = costs[i] + min({climb(i + 1) + 1, climb(i + 2) + 4,
				                          climb(i + 3) + 9});
			}
			return memo[i];
		};

		return climb(0);
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)