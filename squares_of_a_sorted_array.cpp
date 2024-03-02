class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());

        int mini = INT_MAX, minIndex;
        for(int i = 0; i < nums.size(); i++) {
            if(abs(nums[i]) < mini) {
                mini = abs(nums[i]);
                minIndex = i;
            }
        }

        int left = minIndex, right = minIndex+1, index = 0;
        while(left >= 0 && right < nums.size()) {
            if(pow(nums[left], 2) < pow(nums[right], 2)) {
                ans[index++] = pow(nums[left--], 2);
            } else {
                ans[index++] = pow(nums[right++], 2);
            }
        }

        for(int i = left; i >= 0; i--) ans[index++] = pow(nums[i], 2);
        for(int i = right; i < nums.size(); i++) ans[index++] = pow(nums[i], 2);
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)