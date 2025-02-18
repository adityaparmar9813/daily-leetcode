class Solution {
   public:
	string smallestNumber(string pattern) {
		int n = pattern.size();
		string result;
		stack<int> st;

		for (int i = 0; i <= n; i++) {
			st.push(i + 1);

			if (i == n || pattern[i] == 'I') {
				while (!st.empty()) {
					result += to_string(st.top());
					st.pop();
				}
			}
		}

		return result;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)