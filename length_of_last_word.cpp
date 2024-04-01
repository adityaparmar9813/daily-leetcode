class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size()-1;
    
        while(s[index] == ' ') {
            index--;
        }
        
        for(int i = index; i >= 0; i--) {
            if(s[i] == ' ') {
                return index - i;
            }
        }
        return index + 1;
    }
};
