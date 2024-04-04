class Solution {
public:
    int maxDepth(string s) {
        int curr = 0, ans = 0;

        for(char ch: s) {
            if(ch == '(') {
                curr++;
            } else if(ch == ')') {
                curr--;
            }

            ans = max(curr, ans);
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
