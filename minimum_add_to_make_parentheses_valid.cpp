class Solution {
  public:
	int minAddToMakeValid(string s) {
		stack<char> st;

		for (char ch : s) {
			if (ch == ')' && !st.empty() && st.top() == '(') {
				st.pop();
			} else {
				st.push(ch);
			}
		}
		return st.size();
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)