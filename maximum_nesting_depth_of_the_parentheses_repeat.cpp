class Solution {
   public:
	int maxDepth(string s) {
		int depth = 0, ans = 0;

		for (char ch : s) {
			if (ch == '(') {
				depth++;
			}
			if (ch == ')') {
				depth--;
			}
			ans = max(depth, ans);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)