class Solution {
  public:
	string compressedString(string word) {
		int prevLength = 1;
		char prevChar = word[0];
		string ans = "";

		for (int i = 1; i < word.size(); i++) {
			if (word[i] == word[i - 1]) {
				if (prevLength == 9) {
					ans += to_string(9) + prevChar;
					prevLength = 0;
				}
				prevLength++;
			} else {
				ans += to_string(prevLength) + prevChar;
				prevLength = 1;
				prevChar = word[i];
			}
		}
		ans += to_string(prevLength) + prevChar;

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)