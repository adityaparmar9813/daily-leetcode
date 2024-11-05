class Solution {
  public:
	int minChanges(string s) {
		int ans = 0;

		for (int i = 0; i < s.size(); i += 2) {
			if (s[i] != s[i + 1]) {
				ans++;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)