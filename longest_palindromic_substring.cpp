class Solution {
public:
    string check(int left, int right, string s) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    };

    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        string ans = s.substr(0, 1);

        for (int i = 0; i < s.length() - 1; i++) {
            string odd = check(i, i, s);
            string even = check(i, i+1, s);

            if(odd.length() > ans.length()) ans = odd;
            if(even.length() > ans.length()) ans = even;
        }

        return ans;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(1)