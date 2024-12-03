class Solution {
  public:
	string addSpaces(string s, vector<int> &spaces) {
		string ans;
		int currIndex = 0;

		for (int i = 0; i < s.size(); i++) {
			if (currIndex < spaces.size() && spaces[currIndex] == i) {
				ans.push_back(' ');
			}

			if (currIndex < spaces.size() && spaces[currIndex] <= i) {
				currIndex++;
			}

			ans.push_back(s[i]);
		}

		return ans;
	}
};