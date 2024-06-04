class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> mp(58, 0);
        int ans = 0;
        bool hasOdd = false;

        for (auto ch: s) {
            mp[ch - 'A']++;
        }

        for (auto count: mp) {
            ans += (count / 2) * 2;

            if (!hasOdd) {
                hasOdd = !(count % 2 == 0);
            }
        }
        return ans + hasOdd;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
