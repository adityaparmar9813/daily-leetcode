class Solution {
   public:
	string removeOccurrences(string s, string part) {
		int n = s.size(), m = part.size();
		string ans;

		for (int i = 0; i < n; i++) {
			ans.push_back(s[i]);

			if ((s[i] == part[m - 1]) && (ans.size() >= m)) {
				if (part == ans.substr(ans.size() - m)) {
					ans.erase(ans.size() - m);
				}
			}
		}

		return ans;
	}
};

// Time Complexity: O(n * m)
// Space Complexity: O(n)