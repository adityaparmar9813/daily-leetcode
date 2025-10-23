class Solution {
   public:
	bool hasSameDigits(string s) {
		if (s.size() == 2) {
			return s[0] == s[1];
		}

		string str = "";

		for (int i = 1; i < s.size(); i++) {
			str.push_back(((s[i] + s[i - 1] - '0') % 10) + '0');
		}

		return hasSameDigits(str);
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)