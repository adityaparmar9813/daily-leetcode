class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        set<char> mapped;

        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]]) {
                if(mp[s[i]] != t[i]) {
                    return false;
                }
            } else {
                if(mapped.count(t[i])) {
                    return false;
                }
                mp[s[i]] = t[i];
                mapped.insert(t[i]);
            }
        }
        return true;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
