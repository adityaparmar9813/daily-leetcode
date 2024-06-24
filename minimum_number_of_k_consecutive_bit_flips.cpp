class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0, flips = 0;

        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] + flips) % 2 == 0) {
                if (i > nums.size() - k) {
                    return -1;
                } else {
                    ans++;
                    flips++;
                    nums[i] = -1;
                }
            }

            if (i >= k-1) {
                flips -= (nums[i-k+1] < 0);     
            }
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
