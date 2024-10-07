class Solution {
  public:
	int minLength(string s) {
		string str;

		for (char ch : s) {
			if (!str.empty() && ((ch == 'D' && str.back() == 'C') ||
								 (ch == 'B' && str.back() == 'A'))) {
				str.pop_back();
			} else {
				str.push_back(ch);
			}
		}
		return str.size();
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)