class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = 0;

        while(slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)