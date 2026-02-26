class Solution {
   public:
	string increment(string s) {
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '0') {
				s[i] = '1';
				return s;
			}
			s[i] = '0';
		}
		return '1' + s;
	}

	int numSteps(string s) {
		int count = 0;

		while (s != "1") {
			if (s.back() == '1') {
				s = increment(s);
			} else {
				s.pop_back();
			}
			count++;
		}

		return count;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)