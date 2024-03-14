class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int result = 0;
        int l = 0, r = 0, sum = 0, tail = 0;

        while (r < nums.size()) {
            sum += nums[r];
            if (nums[r] == 1) tail = 0;
            
            while (l <= r && sum >= goal) {
                if (sum == goal) tail++;
                sum -= nums[l++];
            }
            result += tail;
            r++;
        }
        return result;
    }
};

// Time Complexity : O(n)
// Speed Complexity : O(1)