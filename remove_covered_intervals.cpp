class Solution {
   public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(),
		     [](vector<int>& a, vector<int>& b) {
			     return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
		     });
		int i = 0, n = intervals.size(), ans = 0;

		while (i < n) {
			int r = intervals[i][1];
			++ans;

			while (i < n && r >= intervals[i][1]) {
				++i;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(1)