class Solution {
   public:
	string makeFancyString(string s) {
		char prev = s[0];
		int count = 1;
		string ans(1, s[0]);

		for (int i = 1; i < s.size(); i++) {
			if (s[i] == prev) {
				count++;
			} else {
				count = 1;
				prev = s[i];
			}

			if (count < 3) {
				ans.push_back(s[i]);
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)