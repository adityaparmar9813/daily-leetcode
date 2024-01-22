class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long sum = (n*(n+1))/2;
        long long sum_sq = (n*(n+1)*(2*n+1))/6;
        long long curr = 0;
        long long curr_sq = 0;

        for(int i=0; i < n; i++) {
            curr += nums[i];
            curr_sq += nums[i] * nums[i];
        }

         int repeat = ((curr-sum) + (curr_sq-sum_sq) / (curr-sum)) / 2;
         int absent = repeat - curr + sum;
         return {repeat, absent};
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
