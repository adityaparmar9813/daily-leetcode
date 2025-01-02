class Solution {
   public:
	inline bool isVowel(char ch) {
		vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
		return find(vowels.begin(), vowels.end(), ch) != vowels.end();
	}

	inline bool check(string s) { return isVowel(s[0]) && isVowel(s.back()); }

	vector<int> vowelStrings(vector<string>& words,
	                         vector<vector<int>>& queries) {
		vector<int> prefix(words.size() + 1, 0), ans(queries.size());

		for (int i = 0; i < words.size(); i++) {
			prefix[i + 1] = prefix[i] + check(words[i]);
		}

		for (int i = 0; i < queries.size(); i++) {
			int l = queries[i][0];
			int r = queries[i][1];
			ans[i] = prefix[r + 1] - prefix[l];
		}

		return ans;
	}
};

// Time Complexity: O(n + q)
// Space Complexity: O(n)