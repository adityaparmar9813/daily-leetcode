class Solution {
   public:
	int maxFreqSum(string s) {
		vector<int> mp(26, 0);

		for (char &ch : s) {
			mp[ch - 'a']++;
		}

		int maxVowel = 0, maxConsonant = 0;

		for (int i = 0; i < 26; i++) {
			if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
				maxVowel = max(maxVowel, mp[i]);
			} else {
				maxConsonant = max(maxConsonant, mp[i]);
			}
		}

		return maxVowel + maxConsonant;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)