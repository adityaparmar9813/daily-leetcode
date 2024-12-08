class Solution {
  public:
	int maxTwoEvents(vector<vector<int>> &events) {
		int n = events.size(), ans = 0;
		sort(events.begin(), events.end());

		vector<int> postfix(n);
		postfix[n - 1] = events[n - 1][2];

		for (int i = n - 2; i >= 0; i--) {
			postfix[i] = max(events[i][2], postfix[i + 1]);
		}

		for (int i = 0; i < n; i++) {
			int l = i + 1, r = n - 1;
			int minIndex = -1;

			while (l <= r) {
				int mid = l + (r - l) / 2;

				if (events[mid][0] > events[i][1]) {
					minIndex = mid;
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}

			int currAns = minIndex == -1 ? events[i][2]
										 : events[i][2] + postfix[minIndex];
			ans = max(ans, currAns);
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)