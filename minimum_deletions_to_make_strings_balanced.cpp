class Solution {
public:
    int minimumDeletions(string s) {
        int a_count = count(s.begin(), s.end(), 'a');
        int b_count = 0, ans = 1e9;
        vector<int> postfix(s.size());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'b') {
                ans = min(ans, a_count + b_count++);
            } else {
                a_count--;
            }
        }

        return ans == INT_MAX ? 0 : min(ans, b_count);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
