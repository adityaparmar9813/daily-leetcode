class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int solve(int index, int balance, const string& s) {
        if (index == n) {
            return balance == 0;
        }
        if (dp[index][balance] != -1) {
            return dp[index][balance];
        }

        int ans = 0;
        switch (s[index]) {
            case '(':
                ans = solve(index + 1, balance + 1, s);
                break;
            case ')':
                if (balance > 0) ans = solve(index + 1, balance - 1, s);
                break;
            case '*':
                ans |= solve(index + 1, balance + 1, s) || solve(index + 1, balance, s);
                if (balance > 0) {
                    ans |= solve(index + 1, balance - 1, s);
                }
        }
        return dp[index][balance] = ans;
    }
    
    bool checkValidString(string s) {
        n = s.size();
        dp.resize(n, vector<int>(2 * n + 1, -1));
        return solve(0, 0, s) == 1;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)
