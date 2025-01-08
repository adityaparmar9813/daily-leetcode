class Solution {
   public:
	bool check(string word1, string word2) {
		if (word1.size() > word2.size()) {
			return false;
		}

		for (int i = 0; i < word1.size(); i++) {
			if (word1[i] != word2[i]) {
				return false;
			}
		}

		for (int i = word1.size(), j = word2.size(); i >= 0; i--, j--) {
			if (word1[i] != word2[j]) {
				return false;
			}
		}

		return true;
	}

	int countPrefixSuffixPairs(vector<string>& words) {
		int ans = 0;

		for (int i = 0; i < words.size(); i++) {
			for (int j = i + 1; j < words.size(); j++) {
				if (check(words[i], words[j])) {
					ans++;
				}
			}
		}

		return ans;
	}
};

// Time Complexity : O(m * n ^ 2)
// Space Complexity : O(1)