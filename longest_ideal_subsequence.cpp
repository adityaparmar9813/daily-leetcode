class Solution {
public:
    int longestIdealString(string& s, int k) {
        vector<int> dp(26, 0);
        
        for(int i = 0; i < s.size(); i++) {
            int index = s[i]-'a';
            int prev = max(0, index-k);
            int next = min(index+k, 25);

            for(int j = prev; j <= next; j++) {
                dp[index] = max(dp[index], dp[j]);
            }
            dp[index]++;
        }
        return *max_element(dp.begin(), dp.end());   
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
