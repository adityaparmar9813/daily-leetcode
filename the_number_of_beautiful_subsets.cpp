class Solution {
public:
    void solve(vector<int>& nums, int index, int k, unordered_map<int, int>& mp, int& count) {
        if (index == nums.size()) {
            count++;
            return;
        }

        solve(nums, index + 1, k, mp, count);

        bool canInclude = true;
        if (mp[nums[index] - k] > 0 || mp[nums[index] + k] > 0) {
            canInclude = false;
        }

        if (canInclude) {
            mp[nums[index]]++;
            solve(nums, index + 1, k, mp, count);
            mp[nums[index]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        solve(nums, 0, k, mp, count);
        return count-1;
    }
};

// Time Complexity : O(2^n)
// Space Complexity : O(n)
