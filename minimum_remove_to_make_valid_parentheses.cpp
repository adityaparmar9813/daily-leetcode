class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        string ans = "";

        for(int i=0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push({s[i], i});
            } else if( s[i] == ')') {
                if(!st.empty() && st.top().first == '(') {
                    st.pop();
                } else {
                    st.push({s[i], i});
                }
            }
        }
        
        for(int i = s.size()-1; i >= 0; i--) {
            if(!st.empty() && st.top().second == i) {
                st.pop();
                continue;
            }
            ans.push_back(s[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
