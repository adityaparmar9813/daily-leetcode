class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp, mpmp;

        for(auto num: arr) {
            mp[num]++;
        }
        for(auto count: mp) {
            mpmp[count.second]++;
        }
        for(auto count: mp) {
            if(mpmp[count.second] != 1) return false;
        }
        return true;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
