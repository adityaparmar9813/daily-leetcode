class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ans = 0;

        for(auto num: nums) {
            if(count == 0) ans = num;

            if(num == ans) count++;
            else count--;
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)