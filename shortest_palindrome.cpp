class Solution {
  public:
	string shortestPalindrome(string s) {
		if (s.empty()) {
			return s;
		}

		string rev_s = s;
		reverse(rev_s.begin(), rev_s.end());
		string combined = s + "#" + rev_s;

		vector<int> lps(combined.size(), 0);

		for (int i = 1; i < combined.size(); i++) {
			int j = lps[i - 1];
			while (j > 0 && combined[i] != combined[j]) {
				j = lps[j - 1];
			}
			if (combined[i] == combined[j]) {
				j++;
			}
			lps[i] = j;
		}

		int longest_palindrome_prefix_length = lps.back();

		string to_add =
			rev_s.substr(0, s.size() - longest_palindrome_prefix_length);

		return to_add + s;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)