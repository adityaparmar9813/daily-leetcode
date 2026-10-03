class Solution {
   public:
	int longestValidParentheses(string s) {
		stack<int> st;
		int res = 0;
		st.push(-1);

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push(i);
			} else {
				st.pop();
				if (st.empty())
					st.push(i);
				else
					res = max(res, i - st.top());
			}
		}
		return res;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)