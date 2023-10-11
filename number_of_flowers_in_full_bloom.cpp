class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> first, second;
        for(auto flower: flowers) {
            first.push_back(flower[0]);
            second.push_back(flower[1]);
        }

        sort(first.begin(), first.end());
        sort(second.begin(), second.end());

        vector<int> ans;
        for(auto person: people) {
            // Find first element whiose start time is greater than visit time
            int i = upper_bound(first.begin(), first.end(), person) - first.begin();
            // FInd first element whose end time is less than visit time
            int j = lower_bound(second.begin(), second.end(), person) - second.begin();
            ans.push_back(i - j);
        }
        return ans;
    }
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)
