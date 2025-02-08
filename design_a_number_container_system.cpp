class NumberContainers {
   public:
	unordered_map<int, set<int>> mp;
	unordered_map<int, int> vec;

	NumberContainers() {}

	void change(int index, int number) {
		if (vec.find(index) != vec.end()) {
			mp[vec[index]].erase(index);
		}

		vec[index] = number;
		mp[number].insert(index);
	}

	int find(int number) {
		return mp[number].empty() ? -1 : *mp[number].begin();
	}
};

// Time Complexity : O(log(n))
// Space Complexity : O(n)