class Solution {
  public:
	bool canChange(string start, string target) {
		stack<pair<char, int>> st;

		int n = start.size();
		for (int i = n - 1; i >= 0; i--) {
			if (start[i] == 'L' || start[i] == 'R') {
				st.push({start[i], i});
			}
		}

		for (int i = 0; i < n; i++) {
			if (target[i] == '_')
				continue;
			if (st.empty() || st.top().first != target[i] ||
				(target[i] == 'L' && st.top().second < i) ||
				(target[i] == 'R' && st.top().second > i)) {
				return false;
			}
			st.pop();
		}

		return st.empty();
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)