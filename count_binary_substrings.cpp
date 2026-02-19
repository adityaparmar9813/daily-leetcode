class Solution {
   public:
	int countBinarySubstrings(string s) {
		int prev = 0, curr = 1, ans = 0;

		for (int i = 1; i < s.length(); i++) {
			if (s[i] == s[i - 1]) {
				curr++;
			} else {
				ans += min(prev, curr);
				prev = curr;
				curr = 1;
			}
		}
		ans += min(prev, curr);
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)