class Solution {
public:
    int minOperations(vector<int>& nums) {
        int maxi = 0, left = 0, count = 0;

        // Sort Array
        sort(nums.begin(), nums.end());

        // Make Array Unique
        for(int i=0; i < nums.size(); i++) {
            if(i+1 < nums.size() && nums[i] == nums[i+1]) continue;
            nums[left++] = nums[i];
        }

        // Calculate Minimum Operations
        for(int i=0, j=0; i < left; i++) {
            while(j < left && (nums[j] - nums[i]) <= nums.size()-1) {
                count++;
                j++;
            }
            maxi = max(maxi, count);
            count--;
        }
        return nums.size() - maxi;
    }
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)