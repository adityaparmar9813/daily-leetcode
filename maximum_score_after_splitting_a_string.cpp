class Solution {
public:
    int maxScore(string s) {
        int ones=0, zerCount = 0, oneCount = 0, ans = -1;

        for(int i=0; i < s.length(); i++) if(s[i] == '1') ones++;

        for(int i=0; i < s.length()-1; i++) {
            if(s[i] == '0') zerCount++;
            else oneCount++;
            ans = max(ans, zerCount + ones - oneCount);
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)