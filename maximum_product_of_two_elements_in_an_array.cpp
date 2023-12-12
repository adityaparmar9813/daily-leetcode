class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0;
        int maxi = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            ans = max(ans, (maxi - 1) * (nums[i] - 1));
            maxi = max(maxi, nums[i]);
        }

        return ans;        
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)