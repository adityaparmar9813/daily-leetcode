class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for(auto num: nums) {
            // map stores 2 most frequent elements
            mp[num]++;
            // remove all elements if map size grows over two since there 
            // can not be more than two elements which can satisfy the n/3 condition
            if(mp.size() > 2) for(auto el: mp) el.second--;
        }

        for(auto el: mp) {
            int n = el.first, count = 0;
            // calculating actual count of the most frequent elements
            for(auto num: nums) if(num == n) count++;

            if(count > nums.size()/3) ans.push_back(n);
        }

        return ans;
    }
};