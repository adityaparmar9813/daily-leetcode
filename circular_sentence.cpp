class Solution {
  public:
	bool isCircularSentence(string sentence) {
		if (sentence[0] != sentence.back()) {
			return false;
		}

		for (int i = 2; i < sentence.size(); i++) {
			if (sentence[i - 1] == ' ' && sentence[i] != sentence[i - 2]) {
				return false;
			}
		}
		return true;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)