class Solution {
   public:
	int numberOfSpecialChars(string word) {
		vector<int> mp1(26, -1), mp2(26, -1);

		for (int i = 0; i < word.size(); i++) {
			char ch = word[i];

			if (ch >= 'a' && ch <= 'z') {
				mp1[ch - 'a'] = i;
			} else if (ch >= 'A' && ch <= 'Z') {
				if (mp2[ch - 'A'] == -1) {
					mp2[ch - 'A'] = i;
				}
			}
		}

		int ans = 0;

		for (int i = 0; i < 26; i++) {
			if (mp1[i] != -1 && mp2[i] != -1 && mp1[i] < mp2[i]) {
				ans++;
			}
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)