class Solution {
  public:
	bool canMakeSubsequence(string str1, string str2) {
		int i = 0, j = 0;

		while (i < str1.size() && j < str2.size()) {
			if ((str2[j] - str1[i]) == 1 || (str2[j] - str1[i]) == 0 ||
				str1[i] == 'z' && str2[j] == 'a') {
				j++;
			}
			i++;
		}

		return j == str2.size();
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)