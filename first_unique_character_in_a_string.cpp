class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(26, 0);

        for(auto ch: s) mp[ch - 'a']++;

        for(int i=0; i < s.size(); i++) {
            if(mp[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)