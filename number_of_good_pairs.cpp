class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto num: nums) mp[num]++;

        int ans = 0;
        for(auto el: mp) {
            // Contribution of frequency will be the sum of natural numbers till one less than the frequency
            // Like for a frequency of 3 -> the first element will form pairs with the next two
            // While the second element will form pair with only the next element
            int n = el.second-1;
            ans += n*(n+1) / 2;
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)