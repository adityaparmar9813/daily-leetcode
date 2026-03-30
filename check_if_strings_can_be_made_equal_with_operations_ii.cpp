class Solution {
   public:
	bool checkStrings(string s1, string s2) {
		vector<int> mpE1(26, 0), mpE2(26, 0), mpO1(26, 0), mpO2(26, 0);

		for (int i = 0; i < s1.size(); i++) {
			if (i % 2 == 0) {
				mpE1[s1[i] - 'a']++;
			} else {
				mpO1[s1[i] - 'a']++;
			}
		}

		for (int i = 0; i < s2.size(); i++) {
			if (i % 2 == 0) {
				mpE2[s2[i] - 'a']++;
			} else {
				mpO2[s2[i] - 'a']++;
			}
		}

		for (int i = 0; i < 26; i++) {
			if ((mpE1[i] != mpE2[i]) || (mpO1[i] != mpO2[i])) {
				return false;
			}
		}

		return true;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)