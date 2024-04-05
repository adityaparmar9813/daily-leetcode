class Solution {
public:
    string makeGood(string s) {
        string ans = string(1, s[0]);

        for(int i = 1; i < s.size(); i++) {
            if(!ans.empty() && (ans.back() == s[i]+32 || ans.back() == s[i]-32)) {
                ans.pop_back();
            } else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(n)
