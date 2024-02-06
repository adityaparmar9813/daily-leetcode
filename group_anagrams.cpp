class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(auto str: strs) {
            string curr = str;
            sort(curr.begin(), curr.end());

            mp[curr].push_back(str);
        }

        for(auto el: mp) {
            ans.push_back(el.second);
        }
        return ans;
    }
};

// Time Complexity : O(n*log(m))
// Space Complexity : O(n)