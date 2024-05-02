class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        
        while (i < j && nums[i] < 0 && nums[j] > 0) {
            if(abs(nums[i]) == nums[j]) {
                return nums[j];
            }
            if(abs(nums[i]) > nums[j]) {
                i++;
            } else {
                j--;
            }
        }
        return -1;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(1)
