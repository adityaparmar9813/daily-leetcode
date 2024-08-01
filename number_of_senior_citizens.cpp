class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;

        for (string detail: details) {
            ans += ((detail[11]-'0') * 10 + (detail[12]-'0')) > 60;
        }
        return ans;
    }
};

// Time Complexity : O(1)
// Space Complexity : O(1)
