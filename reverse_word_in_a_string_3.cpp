class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0;

        while(end < s.size()) {
            // Stop when we encounter the end of a word
            if(s[end] == ' ' || end == s.size()-1) {
                int ptr = end-1;
                // In case the current word is the final word in the string
                if(end == s.size()-1) ptr = end;

                // Reverse the word
                while(start < ptr) swap(s[start++], s[ptr--]);
                // Start points to the start of the next word
                start = end+1;
            }
            end++;
        }
        return s;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)