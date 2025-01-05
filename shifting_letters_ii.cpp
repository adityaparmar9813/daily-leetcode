class Solution {
   public:
	string shiftingLetters(string s, vector<vector<int>>& shifts) {
		vector<int> sweep(s.size() + 1, 0);

		for (const auto& shift : shifts) {
			int move = shift[2] == 1 ? 1 : -1;
			sweep[shift[0]] += move;
			sweep[shift[1] + 1] -= move;
		}

		int currShift = 0;

		for (int i = 0; i < s.size(); i++) {
			int pos = s[i] - 'a';
			currShift += sweep[i];
			s[i] = (pos + currShift % 26 + 26) % 26 + 'a';
		}

		return s;
	}
};

// Time Complexity: O(n + m)
// Space Complexity: O(n)