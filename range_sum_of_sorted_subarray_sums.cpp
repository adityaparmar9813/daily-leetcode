class Solution {
public:
    const int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subArraySum;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;

            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                subArraySum.push_back(sum);
            }
        }

        sort(subArraySum.begin(), subArraySum.end());
        int ans = 0;

        for (int i = left-1; i < right; i++) {
            ans = (ans + subArraySum[i]) % MOD;
        }
        return ans;
    }
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(1)
