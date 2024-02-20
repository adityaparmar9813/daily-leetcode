class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto num: nums) sum += num;

        return n*(n+1)/2 - sum;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)