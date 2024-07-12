class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0, n = s.size();
        string k;

        char c1 = (x > y ? 'a' : 'b');
        char c2 = (c1 == 'a' ? 'b' : 'a');

        for (int i = 0; i < n; i++) {
            if (!k.empty() && k.back() == c1 && s[i] == c2) {
                ans += max(x, y);
                k.pop_back();
            } else {
                k.push_back(s[i]);
            }
        }

        s = k, n = s.size(), k.clear();

        for (int i = 0; i < n; i++) {
            if (!k.empty() && k.back() == c2 && s[i] == c1) {
                ans += min(x, y);
                k.pop_back();
            } else {
                k.push_back(s[i]);
            }
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
