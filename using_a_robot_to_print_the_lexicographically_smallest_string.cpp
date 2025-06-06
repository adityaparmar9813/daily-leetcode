class Solution {
   public:
	string robotWithString(string s) {
		vector<int> freq(26);
		for (char c : s) {
			freq[c - 'a']++;
		}

		string ans;
		stack<char> st;
		char minChar = 'a';

		for (char c : s) {
			st.push(c);
			freq[c - 'a']--;

			while (minChar <= 'z' && freq[minChar - 'a'] == 0) {
				minChar++;
			}

			while (!st.empty() && st.top() <= minChar) {
				ans += st.top();
				st.pop();
			}
		}

		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)