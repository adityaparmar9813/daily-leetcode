class Solution {
   public:
	int numberOfSpecialChars(string word) {
		vector<bool> mp1(26, 0), mp2(26, 0);

		for (char ch : word) {
			if (ch >= 'a' && ch <= 'z') {
				mp1[ch - 'a'] = true;
			} else if (ch >= 'A' && ch <= 'Z') {
				mp2[ch - 'A'] = true;
			}
		}

		int ans = 0;

		for (int i = 0; i < 26; i++) {
			if (mp1[i] && mp2[i]) {
				ans++;
			}
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)