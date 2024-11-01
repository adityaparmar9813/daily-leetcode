class Solution {
  public:
	string makeFancyString(string s) {
		string ans = "";
		ans.push_back(s[0]);

		char prev = s[0];
		int count = 1;

		for (int i = 1; i < s.size(); i++) {
			if (s[i] == s[i - 1]) {
				count++;
			} else {
				count = 1;
			}

			if (count < 3) {
				ans.push_back(s[i]);
			}
		}
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)