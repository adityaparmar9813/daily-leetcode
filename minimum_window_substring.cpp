class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char, int> freq;

        for(int i=0; i < n; i++) {
            freq[t[i]]++;
        }

        unordered_map<char, deque<int>> pos;
        set<int> st;

        pair<int, int> res = {0, INT_MAX}, initial;
        initial = res;

        for(int i=0; i<m; i++) {
            if(freq[s[i]] > 0) {
                pos[s[i]].push_back(i);
                st.insert(i);
                
                if(pos[s[i]].size() > freq[s[i]]) {
                    int first = pos[s[i]].front();
                    pos[s[i]].pop_front();
                    st.erase(first);
                }

                if(st.size() == n) {
                    if(i - *st.begin() < res.second - res.first) {
                        res = {*st.begin(), i};
                    }
                }
            }
        }
        if(res == initial) return "";
        string ans = s.substr(res.first, res.second - res.first + 1);
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
