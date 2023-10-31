class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int curr = pref[0];
        for(int i=1; i<pref.size(); i++) {
            pref[i] = curr ^ pref[i];
            curr = curr ^ pref[i];
        }

        return pref;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)