class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0;

        while(index < word.size() && word[index] != ch) {
            index++;
        }
        if(word[index] != ch) {
            return word;
        }
        
        reverse(word.begin(), word.begin()+index+1);
        return word;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
