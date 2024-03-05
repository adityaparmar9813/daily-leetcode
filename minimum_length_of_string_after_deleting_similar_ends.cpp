class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size()-1;

        while(l < r && s[l] == s[r]) {
            while(s[l] == s[l+1] && l+1 < r) l++;
            while(s[r] == s[r-1] && l < r-1) r--;
            l++;
            r--;
        }
        return r-l+1;    
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)