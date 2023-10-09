class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int start = 0, end = nums.size()-1;

        // Find first occurence
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(nums[mid] > target) end = mid-1;
            else if(nums[mid] < target) start = mid+1;
            else {
                if(mid == 0 || (nums[mid-1] != target)) {
                    first = mid;
                    break;
                }
                end = mid-1;
            }
        }
        
        start = 0, end = nums.size()-1;

        // Find last occurence
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(nums[mid] > target) end = mid-1;
            else if(nums[mid] < target) start = mid+1;
            else {
                if(mid == nums.size()-1 || (nums[mid+1] != target)) {
                    last = mid;
                    break;
                }
                start = mid+1;
            }
        }
        return {first, last};
    }
};

// Time Complexity : O(logn)
// Space Complexity : O(1)