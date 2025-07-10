
class Solution {
   public:
	int maxFreeTime(int eventTime, vector<int>& startTime,
	                vector<int>& endTime) {
		int n = startTime.size();
		vector<int> gaps(n + 1);
		gaps[0] = startTime[0];
		for (int i = 1; i < n; i++) {
			gaps[i] = startTime[i] - endTime[i - 1];
		}
		gaps[n] = eventTime - endTime[n - 1];

		int ans = 0;
		for (int g : gaps) {
			ans = max(ans, g);
		}

		vector<int> pre(n + 1), suf(n + 1);
		pre[0] = gaps[0];
		for (int i = 1; i <= n; i++) {
			pre[i] = max(pre[i - 1], gaps[i]);
		}
		suf[n] = gaps[n];
		for (int i = n - 1; i >= 0; i--) {
			suf[i] = max(suf[i + 1], gaps[i]);
		}

		for (int i = 0; i < n; i++) {
			int dur = endTime[i] - startTime[i];
			int total = gaps[i] + gaps[i + 1];
			if ((i > 0 && pre[i - 1] >= dur) ||
			    (i + 2 <= n && suf[i + 2] >= dur)) {
				total += dur;
			}
			ans = max(ans, total);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)