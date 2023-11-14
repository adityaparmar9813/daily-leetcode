class Solution {
public:
    int find(string& s, int start) {
        int pos = -1;

        for(int i = start+1; i < s.size(); i++) {
            if(s[i] == s[start]) pos = i;
        }
        return pos;
    }
    int findunique(string &s, int i, int pos) {
        unordered_set<char> unique;

        while(i < pos) {
            unique.insert(s[i]);
            i++;
        }
        return unique.size();
    }

    int countPalindromicSubsequence(string s) {
        unordered_set<char> left;
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            if(left.count(s[i]) == 0) {
                int pos = find(s, i);
                if(pos != -1 && pos - i >= 2) ans += findunique(s, i+1, pos);
                left.insert(s[i]);
            }
        }
        return ans;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)