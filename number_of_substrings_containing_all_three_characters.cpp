class Solution {
   public:
	int numberOfSubstrings(string s) {
		int i = 0, j = 0, ans = 0;
		vector<int> mp(3, 0);

		while (j < s.size()) {
			mp[s[j] - 'a']++;

			while (mp[0] && mp[1] && mp[2]) {
				ans += (s.size() - j);
				mp[s[i] - 'a']--;
				i++;
			}

			j++;
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)