class Solution {
   public:
	int mostBooked(int n, vector<vector<int>>& meetings) {
		sort(meetings.begin(), meetings.end());

		vector<int> roomCount(n, 0);
		priority_queue<int, vector<int>, greater<int>> availableRooms;
		priority_queue<pair<long long, int>, vector<pair<long long, int>>,
		               greater<pair<long long, int>>>
		    busyRooms;

		for (int i = 0; i < n; i++) {
			availableRooms.push(i);
		}

		for (auto& meeting : meetings) {
			long long start = meeting[0];
			long long duration = meeting[1] - meeting[0];

			while (!busyRooms.empty() && busyRooms.top().first <= start) {
				availableRooms.push(busyRooms.top().second);
				busyRooms.pop();
			}

			if (!availableRooms.empty()) {
				int room = availableRooms.top();
				availableRooms.pop();
				busyRooms.push({start + duration, room});
				roomCount[room]++;
			} else {
				auto [endTime, room] = busyRooms.top();
				busyRooms.pop();
				busyRooms.push({endTime + duration, room});
				roomCount[room]++;
			}
		}

		int maxMeetings = 0;
		int result = 0;

		for (int i = 0; i < n; i++) {
			if (roomCount[i] > maxMeetings) {
				maxMeetings = roomCount[i];
				result = i;
			}
		}

		return result;
	}
};

// Time Complexity : O(m * log(m) + n * log(n))
// Space Complexity : O(n + m)