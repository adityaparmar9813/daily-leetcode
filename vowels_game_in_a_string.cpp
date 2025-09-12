class Solution {
   public:
	bool doesAliceWin(string s) {
		for (char &ch : s) {
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
				return true;
			}
		}

		return false;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)