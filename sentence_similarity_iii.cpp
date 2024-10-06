class Solution {
  public:
	bool areSentencesSimilar(string sentence1, string sentence2) {
		string longer =
			sentence1.size() > sentence2.size() ? sentence1 : sentence2;
		string shorter = longer == sentence1 ? sentence2 : sentence1;

		vector<string> longerWords, shorterWords;
		string curr = "";

		for (char ch : longer) {
			if (ch == ' ') {
				longerWords.push_back(curr);
				curr.clear();
			} else {
				curr.push_back(ch);
			}
		}
		longerWords.push_back(curr);
		curr.clear();

		for (char ch : shorter) {
			if (ch == ' ') {
				shorterWords.push_back(curr);
				curr.clear();
			} else {
				curr.push_back(ch);
			}
		}
		shorterWords.push_back(curr);

		int n = shorterWords.size();
		int m = longerWords.size();

		int i = 0, j = 0;

		while (i < n && shorterWords[i] == longerWords[i]) {
			i++;
		}

		while (j < n - i && shorterWords[n - 1 - j] == longerWords[m - 1 - j]) {
			j++;
		}

		return i + j == n;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)