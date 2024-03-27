class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        unsigned long long curr = 1;
        int l = 0, count = 0;

        for(int r=0; r < nums.size(); r++) {
            curr *= nums[r];

            while (curr >= k) {
                curr /= nums[l++];
            }
            count += (r-l+1);
        }
        return count;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
