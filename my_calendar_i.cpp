class MyCalendar {
  public:
	vector<pair<int, int>> bookings;

	MyCalendar() { bookings.clear(); }

	bool book(int start, int end) {
		int l = 0, r = bookings.size() - 1;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (bookings[mid].second > start && bookings[mid].first < end) {
				return false;
			}
			if (bookings[mid].second <= start) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		bookings.insert(bookings.begin() + l, {start, end});
		return true;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)