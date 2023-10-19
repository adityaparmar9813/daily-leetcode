class Solution {
public:
    void convert(string& str) {
        stack<char> st;

        for(auto ch: str) {
            if(ch == '#' && st.empty()) continue;
            else if(ch == '#') st.pop();
            else st.push(ch);
        }
        str = "";
        
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }
    }
    bool backspaceCompare(string s, string t) {
        convert(s);
        convert(t);

        return s == t;
    }
};