class Solution {
public:
    const int MOD = 1e9+7;
    int reverse(int num) {
        int rev = 0;

        while(num != 0) {
            rev = rev*10 + num%10;
            num = num/10;
        }
        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        vector<int> diff(nums.size(), 0);
        unordered_map<int, long long> mp;
        long long ans = 0;

        for(int i=0; i<nums.size(); i++) {
            diff[i] = nums[i] - reverse(nums[i]);
        }

        for(auto num: diff) mp[num]++;

        for(auto el: mp) {
            long long num = el.second;
            ans = (ans % MOD + (num*(num-1) / 2) % MOD) % MOD;
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)