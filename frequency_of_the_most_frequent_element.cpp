class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long l = 0,r = 0;
        long total = 0,ans = 0;

        while (r < nums.size()) {
            total += nums[r];
            while((nums[r] * (r-l+1)) > (total+k)) {
                total -= nums[l];
                l++;
            }
            ans = max(ans, (r-l+1));
            r++;
        }
        return ans;
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(1)