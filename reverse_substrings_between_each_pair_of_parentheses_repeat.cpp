class Solution {
   public:
	string reverseParentheses(string s) {
		int n = s.size();
		vector<int> pair(n);
		stack<int> stack;

		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				stack.push(i);
			} else if (s[i] == ')') {
				int open = stack.top();
				stack.pop();

				pair[open] = i;
				pair[i] = open;
			}
		}

		string ans;
		int step = 1;

		for (int i = 0; i >= 0 && i < n; i += step) {
			if (islower(s[i])) {
				ans += s[i];
			} else {
				i = pair[i];
				step = -step;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)