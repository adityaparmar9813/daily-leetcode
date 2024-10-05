class Solution {
  public:
	bool checkMatch(vector<int> &mp) {
		for (int count : mp) {
			if (count != 0) {
				return false;
			}
		}
		return true;
	}

	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size()) {
			return false;
		}

		vector<int> mp(26, 0);
		bool ans = false;

		for (char ch : s1) {
			mp[ch - 'a']++;
		}

		for (int i = 0; i < s1.size(); i++) {
			mp[s2[i] - 'a']--;
		}
		if (checkMatch(mp)) {
			return true;
		}

		for (int i = s1.size(); i < s2.size(); i++) {
			mp[s2[i] - 'a']--;
			mp[s2[i - s1.size()] - 'a']++;

			if (checkMatch(mp)) {
				return true;
			}
		}
		return false;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)