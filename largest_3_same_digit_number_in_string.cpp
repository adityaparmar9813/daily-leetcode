class Solution {
public:
    string largestGoodInteger(string num) {
        int index = -1;
        string ans = "";

        for(int left = 0; left < num.size()-2; left++) {
            if(num[left] != num[left+1] || num[left] != num[left+2]) continue;
            if(index == -1 || num[left] > num[index]) {
                ans = num.substr(left, 3);
                index = left;
            }
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)