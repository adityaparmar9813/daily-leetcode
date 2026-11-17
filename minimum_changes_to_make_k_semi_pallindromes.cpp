class Solution {
   public:
	int minimumChanges(string s, int k) {
		int n = s.size(), inf = INT_MAX / 2;
		auto peel = [&](int i, int j, int d) {
			int changes = 0;
			for (; j - i > d; i += d, j -= d)
				for (int t = 0; t < d; ++t) changes += s[i + t] != s[j - d + t];
			return changes;
		};

		vector cost(n + 1, vector(n + 1, inf));
		for (int d = 1; 2 * d <= n; ++d)
			for (int length = 2 * d; length <= n; length += d)
				for (int i = 0, j = length; j <= n; ++i, ++j)
					cost[i][j] = min(cost[i][j], peel(i, j, d));

		vector best(n + 1, inf);
		best[0] = 0;
		auto extend = [&](int j) {
			return ranges::min(
			    views::iota(0, j - 1) |
			    views::transform([&](int i) { return best[i] + cost[i][j]; }));
		};
		for (int pieces = 1; pieces < k; ++pieces) {
			vector next(n + 1, inf);
			for (int j = 2 * pieces; j <= n - 2 * (k - pieces); ++j)
				next[j] = extend(j);
			swap(best, next);
		}
		return extend(n);
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)