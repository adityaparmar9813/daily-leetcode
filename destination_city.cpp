class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        string ans;

        for(auto path: paths) {
            mp[path[0]] = mp[path[0]] + 2;
            mp[path[1]]++;
        }

        for(auto &it: mp) if(it.second == 1) return it.first;
        return "";
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)