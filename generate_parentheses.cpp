class Solution {
   public:
	static constexpr char op = '(';

	vector<string> generateParenthesis(int n) {
		if (n-- == 1) return {"()"};

		vector<string> res;
		int sz = n << 1;
		int mask = (1 << n) - 1;

		while (mask < 1 << sz) {
			string s(1, op);
			int bal = 1;

			for (int i = 0; i < sz; i++) {
				int b = (mask >> i) & 1;
				bal += 1 - (b << 1);

				if (bal < 0) break;

				s += op | b;
			}

			if (s.length() - 1 == sz) res.push_back(s += op + 1);

			int c = mask & -mask;
			int r = mask + c;
			mask = (((r ^ mask) >> 2) / c) | r;
		}

		return res;
	}
};

// Time Complexity: O(4 ^ n / n)
// Space Complexity: O(4 ^ n / n)