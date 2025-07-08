class Solution {
   public:
	vector<vector<int>> dp;

	int solve(vector<vector<int>>& events, int index, int k) {
		if (index == events.size() || k == 0) {
			return 0;
		}
		if (dp[index][k] != -1) {
			return dp[index][k];
		}

		int nextIndex = events.size();
		int l = index + 1, r = events.size() - 1;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (events[mid][0] > events[index][1]) {
				nextIndex = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		int take = events[index][2] + solve(events, nextIndex, k - 1);
		int notTake = solve(events, index + 1, k);

		return dp[index][k] = max(take, notTake);
	}

	int maxValue(vector<vector<int>>& events, int k) {
		dp.resize(events.size(), vector<int>(k + 1, -1));
		sort(events.begin(), events.end());
		return solve(events, 0, k);
	}
};

// Time Complexity: O(n * k * log(n))
// Space Complexity: O(n * k)