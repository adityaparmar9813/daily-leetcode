class MyCalendarTwo {
  public:
	map<int, int> mp;
	MyCalendarTwo() {}

	bool book(int start, int end) {
		int sum = 0;
		mp[start]++;
		mp[end]--;

		for (const auto &it : mp) {
			sum += it.second;

			if (sum > 2) {
				mp[start]--;
				mp[end]++;
				return false;
			}
		}
		return true;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)