class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int, int> mp;
        vector<string> result(n);
        
        for (int i = 0; i < n; i++) {
            mp[score[i]] = i;
        }       

        sort(score.begin(), score.end(), greater<int>());  

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                result[mp[score[i]]] = "Gold Medal";
            } else if (i == 1) {
                result[mp[score[i]]] = "Silver Medal";
            } else if (i == 2) {
                result[mp[score[i]]] = "Bronze Medal";
            } else {
                result[mp[score[i]]] = to_string(i + 1);
            }
        }
        
        return result;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(n)
