class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";

        for (int i=0; i < nums.size(); i++) {
            char current = nums[i][i];
            char add = (current == '0') ? '1' : '0';

            ans += add;
        }

        return ans;
    }
};