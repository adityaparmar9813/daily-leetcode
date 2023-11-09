class Solution {
public:
    const int MOD = 1e9+7;
    int countHomogenous(string s) {
        int l = 0;
        long long int res = 0;
        
        for (int r = 0; r < s.length(); r++) {
            if (s[l] == s[r]) res += r-l+1;
            else {
                res++;
                l = r;
            }
        }
        return int(res % MOD);        
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)