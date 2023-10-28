class Solution {
public:
    vector<vector<int>> dp;
    const int MOD = 1e9+7;
    int solve(string s, int n) {
        if(s.size() == n) return 1;
        int ans = 0;

        char ch = s[s.size()-1];
        if(dp[ch-'a'][s.size()] != -1) return dp[ch-'a'][s.size()];

        switch(ch) {
            case 'a':
            ans += solve(s+'e', n);
            break;
            case 'e':
            ans += (solve(s+'a', n) + solve(s+'i', n)) % MOD;
            break;
            case 'i':
            ans += ((solve(s+'a', n) + solve(s+'e', n)) % MOD + (solve(s+'o', n) + solve(s+'u', n)) % MOD) % MOD;
            break;
            case 'o':
            ans += (solve(s+'i', n) + solve(s+'u', n)) % MOD;
            break;
            case 'u':
            ans += solve(s+'a', n) % MOD;
            break;
        }

        return dp[ch-'a'][s.size()] = ans;
    }
    int countVowelPermutation(int n) {
        dp.resize(26, vector<int>(n+1, -1));
        return (((solve("a", n) + solve("e", n)) % MOD + (solve("i", n) + solve("o", n)) % MOD ) % MOD + solve("u", n)) % MOD;
    }
};