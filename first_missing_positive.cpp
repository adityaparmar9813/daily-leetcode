class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] == i+1 || nums[i] < 1 || nums[i] > nums.size() || nums[nums[i]-1] == nums[i]) {
                continue;
            }
            swap(nums[i], nums[nums[i--]-1]);
        }

        int i;
        for(i=0; i < nums.size(); i++) {
            if(nums[i] != i+1) {
                return i+1;
            }
        }
        return i+1;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
