class Solution {
   public:
	bool areAlmostEqual(string s1, string s2) {
		int diff1 = -1, diff2 = -1;

		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				if (diff1 != -1 && diff2 != -1) {
					return false;
				}
				if (diff1 == -1) {
					diff1 = i;
				} else {
					diff2 = i;
				}
			}
		}

		if (diff1 == diff2) {
			return true;
		}
		if (diff1 == -1 || diff2 == -1) {
			return false;
		}

		return (s1[diff1] == s2[diff2] && s1[diff2] == s2[diff1]);
	}
};

// Time complexity: O(n)
// Space complexity: O(1)