static int lps[100];

class Solution {
   public:
	static void preKMP(const string& pattern) {
		int len = 0;
		const int n = pattern.size();

		lps[0] = 0;

		for (int i = 1; i < n; i++) {
			while (len > 0 && pattern[i] != pattern[len]) {
				len = lps[len - 1];
			}

			lps[i] = (pattern[i] == pattern[len]) ? ++len : len;
		}
	}

	static int KMPfind(const string& s, const string& pattern) {
		preKMP(pattern);

		const int sz = s.size();
		const int pz = pattern.size();

		for (int i = 0, j = 0; i < sz; i++) {
			while (j > 0 && s[i] != pattern[j]) {
				j = lps[j - 1];
			}

			if (s[i] == pattern[j]) {
				j++;
			}

			if (j == pz) {
				return i - j + 1;
			}
		}

		return -1;
	}

	static int numOfStrings(vector<string>& patterns, string& word) {
		int cnt = 0;

		for (const auto& p : patterns) {
			cnt += KMPfind(word, p) != -1;
		}

		return cnt;
	}
};

// Time Complexity: O(n * m)
// Space Complexity: O(m)