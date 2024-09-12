class Solution {
  public:
	int countConsistentStrings(string allowed, vector<string> &words) {
		unordered_map<char, int> mp;
		int ans = 0;

		for (char ch : allowed) {
			mp[ch]++;
		}

		for (string word : words) {
			for (char ch : word) {
				if (mp.find(ch) == mp.end()) {
					ans--;
					break;
				}
			}
			ans++;
		}
		return ans;
	}
};

// Time Complexity : O(n * m)
// Space Complexity : O(1)