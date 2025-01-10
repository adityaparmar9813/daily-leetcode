class Solution {
   public:
	vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
		vector<string> ans;
		vector<int> maxFreq(26, 0);

		for (string word2 : words2) {
			vector<int> freq(26, 0);
			for (char ch : word2) {
				freq[ch - 'a']++;
			}
			for (int i = 0; i < 26; i++) {
				maxFreq[i] = max(maxFreq[i], freq[i]);
			}
		}

		for (string word1 : words1) {
			vector<int> freq(26, 0);
			for (char ch : word1) {
				freq[ch - 'a']++;
			}

			bool isUniversal = true;
			for (int i = 0; i < 26; i++) {
				if (freq[i] < maxFreq[i]) {
					isUniversal = false;
					break;
				}
			}

			if (isUniversal) {
				ans.push_back(word1);
			}
		}

		return ans;
	}
};

// Time Complexity: O(n + m)
// Space Complexity: O(1)