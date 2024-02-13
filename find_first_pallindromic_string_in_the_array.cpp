class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto word: words) {
            string temp = word;
            reverse(word.begin(), word.end());
            if(word == temp) return word;
        }
        return "";
    }
};

// Time Complexity : O(n*m)
// Space Complexity : O(1)