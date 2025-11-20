class Solution {
   public:
	static bool cmp(vector<int>& X, vector<int>& Y) {
		const int x0 = X[0], x1 = X[1], y0 = Y[0], y1 = Y[1];
		return (x0 == y0) ? x1 < y1 : x0 > y0;
	}

	int intersectionSizeTwo(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), cmp);

		int cnt = 2, n = intervals.size();

		int a = intervals[0][0];
		int b = a + 1;

		for (int i = 1; i < n; i++) {
			const int L = intervals[i][0];
			const int R = intervals[i][1];

			if (b <= R) continue;

			bool NO = R < a;
			cnt += 1 + NO;

			b = NO ? L + 1 : a;
			a = L;
		}

		return cnt;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)