class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> v;

        for (int i = 0; i < names.size(); i++) {
            v.push_back({heights[i], names[i]});
        }

        sort(v.begin(), v.end(), greater<>());

        for (int i = 0; i < names.size(); i++) {
            names[i] = v[i].second;
        }
        return names;
    }
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)
