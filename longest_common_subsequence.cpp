class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return lcsMemo(text1, text2, m, n, memo);
    }

private:
    int lcsMemo(string& text1, string& text2, int m, int n, vector<vector<int>>& memo) {
        if (m == 0 || n == 0) return 0;

        if (memo[m][n] != -1) return memo[m][n];

        if (text1[m - 1] == text2[n - 1])
            memo[m][n] = 1 + lcsMemo(text1, text2, m-1, n-1, memo);
        else
            memo[m][n] = max(lcsMemo(text1, text2, m-1, n, memo), 
            lcsMemo(text1, text2, m, n - 1, memo));

        return memo[m][n];
    }
};

// Time Complexity : O(n*m)
// Space Complexity : O(n*m)
