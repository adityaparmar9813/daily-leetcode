class AllOne {
	int maxi;
	int mini;
	unordered_map<string, int> count;
	unordered_map<int, set<string>> mp;

  public:
	AllOne() {
		maxi = 0;
		mini = INT_MAX;
	}

	void inc(string key) {
		int curr_count = count[key];

		if (curr_count > 0) {
			mp[curr_count].erase(key);

			if (mp[curr_count].empty()) {
				mp.erase(curr_count);

				if (curr_count == mini) {
					mini = mp.empty() ? INT_MAX : mp.begin()->first;
				}
			}
		}

		count[key]++;
		mp[count[key]].insert(key);
		maxi = max(maxi, count[key]);

		if (mini == INT_MAX || count[key] < mini) {
			mini = count[key];
		}
	}

	void dec(string key) {
		mp[count[key]].erase(key);

		if (mp[count[key]].empty()) {
			mp.erase(count[key]);

			if (count[key] == mini) {
				mini = mp.empty() ? INT_MAX : mp.begin()->first;
			}
		}

		count[key]--;
		int new_count = count[key];

		if (new_count > 0) {
			mp[new_count].insert(key);
			mini = min(mini, new_count);
		} else {
			count.erase(key);
		}

		if (mp.find(maxi) == mp.end()) {
			maxi--;
		}
	}

	string getMaxKey() {
		if (maxi == 0) {
			return "";
		}
		return *mp[maxi].begin();
	}

	string getMinKey() {
		if (mini == INT_MAX) {
			return "";
		}
		return *mp[mini].begin();
	}
};

// Time Complexity : O(log(n))
// Space Complexity : O(n)