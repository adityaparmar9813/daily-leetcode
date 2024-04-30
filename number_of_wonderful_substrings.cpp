class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int mask = 0;
        vector<int> dp(1025);
        dp[0]++;

        for (char ch: word) {
            mask ^= (1 << (ch - 'a'));
            dp[mask]++;
        }

        long long ans = 0;
        for (int i = 0; i < 1024; i++) {
            if (dp[i] == 0) {
                continue;
            }

            int sum = dp[i];
            for (int j = 0; j < 10; j++) {
                sum += dp[i ^ (1 << j)];
            }
            ans += (1LL*sum-1) * dp[i];
        }
        return ans / 2;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
