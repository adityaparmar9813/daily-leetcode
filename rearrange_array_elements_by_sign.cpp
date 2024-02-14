class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int index = 0, positive = 0, negative = 1;

        while (index < nums.size()) {
            if (nums[index++] > 0) {
                ans[positive] = nums[index-1];
                positive += 2;
            } else {
                ans[negative] = nums[index-1];
                negative += 2;
            }
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)