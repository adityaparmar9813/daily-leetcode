class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return findTotalSubArrays(nums, k) - findTotalSubArrays(nums, k-1);
    }

    int findTotalSubArrays(vector<int>& nums, int k) {
        int i = 0, j = 0, ans = 0, oddCount = 0;

        while (j < nums.size()) {
            if (nums[j] % 2 != 0) {
                oddCount++;
            }

            while (oddCount > k) {
                if (nums[i] % 2 != 0) {
                    oddCount--;
                }
                i++;
            }

            ans += j-i+1;
            j++;
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
