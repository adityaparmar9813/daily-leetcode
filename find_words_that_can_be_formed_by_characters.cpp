class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> char_count(26, 0);

        for(auto ch: chars) char_count[ch - 'a']++;

        int ans = 0;

        for(auto word: words) {
            bool flag = true;
            vector<int> current_char_count(26);

            for(auto ch: word) current_char_count[ch - 'a']++;

            for(int i = 0; i < 26; i++) {
                if(char_count[i] < current_char_count[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans += word.length();
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)