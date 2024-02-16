class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        vector<int> frequency;

        for(auto num: arr) mp[num]++;
        for(auto el: mp) frequency.push_back(el.second);

        sort(frequency.begin(), frequency.end());
        for(int i = 0; i < frequency.size(); i++) {
            k = k - frequency[i];
            if(k < 0) return frequency.size() - i;
        }
        return 0;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(n)