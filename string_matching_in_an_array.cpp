class Solution {
   public:
	vector<string> stringMatching(vector<string>& words) {
		vector<string> ans;

		sort(words.begin(), words.end(), [](string word1, string word2) {
			return word1.size() > word2.size();
		});

		for (int i = 0; i < words.size() - 1; i++) {
			if (words[i] != "*") {
				for (int j = i + 1; j < words.size(); j++) {
					if (words[i].find(words[j]) != string::npos) {
						ans.push_back(words[j]);
						words[j] = "*";
					}
				}
			}
		}
		return ans;
	}
};

// Time Complexity: O(m * n ^ 2)
// Space Complexity: O(1)