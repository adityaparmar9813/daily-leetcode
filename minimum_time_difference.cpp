class Solution {
  public:
	int findMinDifference(vector<string> &timePoints) {
		vector<int> time;

		for (string tp : timePoints) {
			int hour = (tp[0] - 'a') * 10 + (tp[1] - 'a');
			int minutes = (tp[3] - 'a') * 10 + (tp[4] - 'a');

			time.push_back(hour * 60 + minutes);
		}

		sort(time.begin(), time.end());
		int ans = INT_MAX;

		for (int i = 1; i < time.size(); i++) {
			int diff = min(time[i] - time[i - 1], time[i - 1] - time[i] + 1440);
			ans = min(ans, diff);
		}
		int diff = min(time.back() - time[0], time[0] - time.back() + 1440);
		ans = min(ans, diff);

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)