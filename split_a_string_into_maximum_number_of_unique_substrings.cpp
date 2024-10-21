class Solution {
  public:
	int solve(string s, int index, string curr, set<string> &st) {
		if (index == s.size()) {
			return 0;
		}

		curr.push_back(s[index]);

		int ans = solve(s, index + 1, curr, st);

		if (!st.count(curr)) {
			st.insert(curr);
			ans = max(ans, 1 + solve(s, index + 1, "", st));
			st.erase(curr);
		}

		return ans;
	}
	int maxUniqueSplit(string s) {
		set<string> st;
		return solve(s, 0, "", st);
	}
};

// Time Complexity : O(2 ^ n)
// Space Complexity : O(n * 2 ^ n)