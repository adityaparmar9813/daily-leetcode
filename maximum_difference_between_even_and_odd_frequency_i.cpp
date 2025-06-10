class Solution {
   public:
	int maxDifference(string s) {
		vector<int> mp(26, 0);

		for (char ch : s) {
			mp[ch - 'a']++;
		}

		int maxOddFreq = 0, minEvenFreq = 1e9;

		for (int i = 0; i < 26; i++) {
			if (mp[i] % 2 == 0) {
				minEvenFreq =
				    mp[i] == 0 ? minEvenFreq : min(minEvenFreq, mp[i]);
			} else {
				maxOddFreq = max(maxOddFreq, mp[i]);
			}
		}

		return maxOddFreq - minEvenFreq;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)
