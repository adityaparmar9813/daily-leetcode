class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        int index = 0, ans = 0;

        while (sum < n) {
            if (index < nums.size() && nums[index] <= sum+1) {
                sum += nums[index++];
            } else {
                ans++;
                sum += sum+1;
            }
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
