class Solution {
public:
    string removeKdigits(string num, int k) {
        const int n = num.size();
        string ans;

        for (char c : num) {
            while (!ans.empty() && ans.back() > c && k > 0) {
                ans.pop_back();
                k--;
            }

            if (!ans.empty() || c != '0') ans.push_back(c);
        }

        while (k > 0 && !ans.empty()) {
            k--;
            ans.pop_back();
        }

        return ans == "" ? "0" : ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
