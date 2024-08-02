class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOneCount = count(nums.begin(), nums.end(), 1);
        int currOneCount = 0, maxOneCount = 0;

        for (int i = 0; i < totalOneCount; i++) {
            currOneCount += nums[i] == 1;
            maxOneCount = max(currOneCount, maxOneCount);
        }

        for (int i = 1; i < nums.size(); i++) {
            currOneCount -= nums[i-1] == 1;
            currOneCount += nums[(i + totalOneCount - 1) % nums.size()] == 1;
            maxOneCount = max(currOneCount, maxOneCount);

        }
        return totalOneCount - maxOneCount;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
