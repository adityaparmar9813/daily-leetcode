class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int curr = 0, ans = 0;
        
        int l = 0, r = tokens.size()-1;
        while(l <= r) {
            if(power >= tokens[l]) {
                curr++;
                power = power-tokens[l++];
                ans = max(curr, ans);
            } else if(curr >= 1) {
                curr--;
                power = power+tokens[r--];
            } else break;
        }
        return ans;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(1)