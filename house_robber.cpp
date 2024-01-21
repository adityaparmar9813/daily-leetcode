class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int b = nums[nums.size()-1];
        int a = nums[nums.size()-2];

        for(int i=nums.size()-3; i >= 0; i--) {
            int temp = a;
            a = nums[i]+b;
            b = max(temp, b);
        }
        return max(a, b);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
