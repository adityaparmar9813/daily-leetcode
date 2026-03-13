class Solution {
   public:
	long long minNumberOfSeconds(int height, vector<int>& times) {
		long long lo = 1, hi = 1e16;

		while (lo < hi) {
			long long mid = (lo + hi) >> 1;
			long long tot = 0;

			for (int i = 0; i < times.size() && tot < height; i++) {
				tot +=
				    (long long)(sqrt((double)mid / times[i] * 2 + 0.25) - 0.5);
			}
			if (tot >= height) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}

		return lo;
	}
};

// Time Complexity : O(n * sqrt(n))
// Space Complexity : O(1)