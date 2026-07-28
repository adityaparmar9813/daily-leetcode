class Solution {
   public:
	string smallestPalindrome(string s) {
		vector<int> mp(26, 0);
		int n = s.size();

		for (char ch : s) {
			mp[ch - 'a']++;
		}

		string ans = "";
		char unique = ' ';

		for (int i = 0; i < 26; i++) {
			if (mp[i] == 0) {
				continue;
			}

			while (mp[i] > 1) {
				mp[i] -= 2;
				ans.push_back('a' + i);
			}

			if (mp[i] == 1) {
				unique = 'a' + i;
			}
		}

		int k = ans.size() - 1;

		if (unique != ' ') {
			ans.push_back(unique);
		}

		for (int i = k; i >= 0; i--) {
			ans.push_back(ans[i]);
		}
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)