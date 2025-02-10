class Solution {
   public:
	string clearDigits(string s) {
		string ans;

		for (char ch : s) {
			if (!ans.empty() && (ch >= '0' && ch <= '9')) {
				ans.pop_back();
				continue;
			}
			ans.push_back(ch);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)