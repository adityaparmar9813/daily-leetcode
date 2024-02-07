class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        vector<pair<int, char>> v;
        string ans = "";

        for(auto ch: s) mp[ch]++;

        for(auto el: mp) {
            v.push_back({el.second, el.first});
        }

        sort(v.begin(), v.end(), greater<pair<int, char>>());

        for(auto el: v) {
            while(el.first--) ans += el.second;
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)