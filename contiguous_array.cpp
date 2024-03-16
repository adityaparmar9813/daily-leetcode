class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int diff = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for(int i=0; i < nums.size(); i++) {
            if(nums[i] == 1) diff++; 
            else diff--;

            if(mp.count(diff)) {
                ans = max(ans, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)