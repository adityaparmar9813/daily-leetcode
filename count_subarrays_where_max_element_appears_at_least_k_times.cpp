class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size(), count = 0;
        long long ans = 0;

        for(int l=0, r=0; r < n; r++) {
            count += (nums[r] == maxi);
            
            while(count >= k) {
                count -= (nums[l++] == maxi);
            }
            ans += l;
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
