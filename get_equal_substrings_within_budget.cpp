class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, cost = 0, n = s.size();
        int l = 0, r = 0;

        while (r < n) {
            cost += abs(s[r] - t[r]);

            if (cost > maxCost) {
                cost -= abs(s[l] - t[l++]);
            } else {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
