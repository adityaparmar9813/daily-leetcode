class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(auto num: nums) ans += num;

        for(int i = nums.size()-1; i >= 2; i--) {
            if(ans > nums[i]*2) return ans;
            ans -= nums[i];
        }
        return -1;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(1)