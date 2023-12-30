class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> mp(26, 0);
        int n = words.size();

        for(auto word: words) {
            for(auto letter: word) mp[letter-'a']++;
        }

        for(int i=0; i<26; i++) if(mp[i] % n != 0) return false;
        return true;
    }
};

// Time Complexity : O(n*m)
// Space Complexity : O(1)