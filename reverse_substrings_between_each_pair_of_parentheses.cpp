class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int curr = i;
                int prev = st.top();
                st.pop();

                while (prev <= curr) {
                    swap(s[prev++], s[curr--]);
                }
            }
        }

        string ans = "";

        for (char ch: s) {
            if (ch == '(' || ch == ')') {
                continue;
            }
            ans.push_back(ch);
        }
        return ans;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)
