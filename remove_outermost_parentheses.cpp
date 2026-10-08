class Solution {
   public:
	string removeOuterParentheses(string& s) {
		int balance = 0, j = 0;

		for (char ch : s) {
			balance += 1 - ((ch - '(') << 1);
			s[j] = ch;
			j += !(balance + ch - '(' == 1);
		}
		s.resize(j);
		return s;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)