class Solution {
   public:
	bool checkString(string s) {
		bool hasB = false;

		for (char ch : s) {
			if (ch == 'b' && !hasB) {
				hasB = true;
			}
			if (ch == 'a' && hasB) {
				return false;
			}
		}

		return true;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)