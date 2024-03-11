class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> mp(26, 0);
        for(int i=0; i < order.size(); i++) {
            mp[order[i]-'a'] = i;
        }

        sort(s.begin(), s.end(), [&](char ch1, char ch2) {
            return mp[ch1-'a'] < mp[ch2-'a'];
        });
        return s;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(n)