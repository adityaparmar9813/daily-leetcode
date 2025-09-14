class Solution {
   public:
	inline bool isVowel(char ch) {
		ch = tolower(ch);
		return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
	}

	string toLower(const string& word) {
		string res;
		res.reserve(word.size());
		for (char ch : word) res.push_back(tolower(ch));
		return res;
	}

	string maskVowels(const string& word) {
		string res;
		res.reserve(word.size());
		for (char ch : word) {
			res.push_back(isVowel(ch) ? '_' : tolower(ch));
		}
		return res;
	}

	vector<string> spellchecker(vector<string>& wordlist,
	                            vector<string>& queries) {
		unordered_map<string, string> exact, cap, vowel;

		for (string& word : wordlist) {
			if (exact.find(word) == exact.end()) exact[word] = word;

			string lower = toLower(word);
			if (cap.find(lower) == cap.end()) cap[lower] = word;

			string vow = maskVowels(word);
			if (vowel.find(vow) == vowel.end()) vowel[vow] = word;
		}

		int q = queries.size();
		vector<string> ans(q, "");

		for (int i = 0; i < q; i++) {
			string query = queries[i];

			if (exact.find(query) != exact.end()) {
				ans[i] = exact[query];
				continue;
			}

			string lower = toLower(query);
			if (cap.find(lower) != cap.end()) {
				ans[i] = cap[lower];
				continue;
			}

			string vow = maskVowels(query);
			if (vowel.find(vow) != vowel.end()) {
				ans[i] = vowel[vow];
			}
		}

		return ans;
	}
};

// Time Complexity: O(m + n)
// Space Complexity: O(m)