class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mini = -1, maxi = -1;
        int i = 0, j = 0, n = nums.size();
        long long cnt = 0;

        while(j < n) {
            if(nums[j] < minK or nums[j] > maxK) {
                mini = maxi = -1;
                i = j+1;
            }
            if(nums[j] == minK) mini = j;
            if(nums[j] == maxK) maxi = j;

            cnt += max(0, min(mini, maxi)-i+1); 
            j++;
        }
        return cnt;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
