class Solution {
public:
    int helper(vector<int>& nums, int index, int curr) {
        if (index == nums.size()) {
            return curr;
        }

        int take = helper(nums, index + 1, curr ^ nums[index]);
        int notTake = helper(nums, index + 1, curr);
        
        return take + notTake;
    }

    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};

// Time Complexity : O(2^n)
// Space Complexity : O(n)
