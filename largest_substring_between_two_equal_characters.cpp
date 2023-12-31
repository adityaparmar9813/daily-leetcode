class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> first;
        int ans = -1;

        for(int i=0; i < s.size(); i++) {
            char ch = s[i];
            if(!first[ch]) first[ch] = i+1;
            else ans = max(ans, i-first[ch]);
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)