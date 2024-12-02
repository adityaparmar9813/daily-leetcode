class Solution {
  public:
	vector<int> computeLPS(const string &pattern) {
		int m = pattern.size();
		vector<int> lps(m, 0);
		int len = 0;
		int i = 1;

		while (i < m) {
			if (pattern[i] == pattern[len]) {
				len++;
				lps[i] = len;
				i++;
			} else {
				if (len != 0) {
					len = lps[len - 1];
				} else {
					lps[i] = 0;
					i++;
				}
			}
		}
		return lps;
	}

	bool isPrefixUsingKMP(const string &text, const string &pattern) {
		int n = text.size();
		int m = pattern.size();

		if (m > n)
			return false;

		vector<int> lps = computeLPS(pattern);
		int i = 0, j = 0;

		while (i < n) {
			if (pattern[j] == text[i]) {
				i++;
				j++;
			}

			if (j == m) {

				if (i - j == 0)
					return true;
				return false;
			} else if (i < n && pattern[j] != text[i]) {
				if (j != 0) {
					j = lps[j - 1];
				} else {
					i++;
				}
			}
		}
		return false;
	}

	int isPrefixOfWord(string sentence, string searchWord) {
		int index = 1;
		string word = "";
		for (char ch : sentence) {
			if (ch == ' ') {
				if (isPrefixUsingKMP(word, searchWord)) {
					return index;
				}
				index++;
				word = "";
			} else {
				word += ch;
			}
		}

		if (!word.empty() && isPrefixUsingKMP(word, searchWord)) {
			return index;
		}
		return -1;
	}
};