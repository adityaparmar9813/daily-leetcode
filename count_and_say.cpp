class Solution {
   public:
	string solve(int curr, int n, string s) {
		if (curr == n) {
			return s;
		}

		int count = 1;
		string newS = "";

		for (int i = 1; i < s.size(); i++) {
			if (s[i] != s[i - 1]) {
				newS += to_string(count) + s[i - 1];
				count = 1;
			} else {
				count++;
			}
		}
		newS += to_string(count) + s.back();

		return solve(curr + 1, n, newS);
	}

	string countAndSay(int n) { return solve(1, n, "1"); }
};

// Time Complexity: O(2 ^ n)
// Space Complexity: O(n)