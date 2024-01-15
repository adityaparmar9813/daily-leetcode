class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> s;
        unordered_map<int, int> losses;
        vector<vector<int>> ans(2);

        for(auto el: matches) {
            s.insert(el[0]);
            s.insert(el[1]);
            losses[el[1]]++;
        }

        for(auto el: s) {
            if(losses[el] == 0) ans[0].push_back(el);
            else if(losses[el] == 1) ans[1].push_back(el);
        }
        return ans;
    }
};

// Time Compleixty: O(n)
// Space Complexity: O(n)
