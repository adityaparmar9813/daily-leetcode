class Solution {
public:
    int appendCharacters(string s, string t) {
        int ptr = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[ptr]) {
                ptr++;
            }
        }
        return t.size() - ptr;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
