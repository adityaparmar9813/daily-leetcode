class Solution {
   public:
	int prefixCount(vector<string>& words, string pref) {
		int ans = 0;

		for (string word : words) {
			bool match = true;

			for (int i = 0; i < pref.size(); i++) {
				if (word[i] != pref[i]) {
					match = false;
					break;
				}
			}

			ans += match;
		}

		return ans;
	}
};

// Time Complexity: O(n * m)
// Space Complexity: O(1)