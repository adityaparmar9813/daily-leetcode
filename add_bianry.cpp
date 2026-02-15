class Solution {
   public:
	string addBinary(string a, string b) {
		int carry = 0, m = a.size(), n = b.size();

		string s1 = m >= n ? a : b;
		string s2 = m < n ? a : b;

		string padding = "";
		for (int i = 0; i < s1.size() - s2.size(); i++) {
			padding.push_back('0');
		}
		s2 = padding + s2;

		for (int i = s1.size() - 1; i >= 0; i--) {
			int curr = carry + (s1[i] - '0') + (s2[i] - '0');

			if (curr <= 1) {
				s1[i] = curr + '0';
				carry = 0;
			} else {
				s1[i] = (curr - 2) + '0';
				carry = 1;
			}
		}

		if (carry) {
			s1 = '1' + s1;
		}

		return s1;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)