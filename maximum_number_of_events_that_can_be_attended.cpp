class Solution {
   public:
	int maxEvents(vector<vector<int>>& events) {
		sort(events.begin(), events.end());
		priority_queue<int, vector<int>, greater<int>> pq;

		int i = 0, res = 0, n = events.size();
		int lastDay = 0;

		for (const auto& e : events) {
			lastDay = max(lastDay, e[1]);
		}

		for (int d = 1; d <= lastDay; ++d) {
			while (i < n && events[i][0] == d) {
				pq.push(events[i++][1]);
			}

			while (!pq.empty() && pq.top() < d) {
				pq.pop();
			}

			if (!pq.empty()) {
				pq.pop();
				++res;
			}
		}

		return res;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)