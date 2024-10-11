class Solution {
  public:
	int smallestChair(vector<vector<int>> &times, int tf) {
		int n = times.size();
		vector<pair<pair<int, int>, int>> events;

		for (int i = 0; i < n; i++) {
			events.push_back({{times[i][0], 1}, i});
			events.push_back({{times[i][1], -1}, i});
		}

		sort(events.begin(), events.end());

		vector<int> assignedChairs(n, -1);
		priority_queue<int, vector<int>, greater<int>> availableChairs;

		for (int i = 0; i < n; i++) {
			availableChairs.push(i);
		}

		for (auto &event : events) {
			int time = event.first.first;
			int type = event.first.second;
			int person = event.second;

			if (person == tf && type == 1) {
				return availableChairs.top();
			}

			if (type == 1) {
				assignedChairs[person] = availableChairs.top();
				availableChairs.pop();
			} else {
				availableChairs.push(assignedChairs[person]);
			}
		}

		return -1;
	}
};

// Time Compleexity : O(n * log(n))
// Space Complexity : O(n)