class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l = k;
        int r = k;
        int maxi = INT_MIN;
        int n = nums.size();
        int mini = nums[k];

        while(l >= 0 && r < n) {
            maxi = max(maxi, mini*(r-l+1));

            if(r+1 < n && l-1 >= 0) {
                if(nums[r+1] > nums[l-1]) {
                    r++;
                    mini = min(mini, nums[r]);
                }
                else {
                    l--;
                    mini = min(mini, nums[l]);
                }
            }
            else if(r+1 >= n && --l >= 0) mini = min(mini, nums[l]);
            else if(l-1 < 0 && ++r < n) mini = min(mini, nums[r]);
        }
        return maxi;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)