class Solution {
public:
    void findHelper(int index, string s, string curr, unordered_map<string, bool>& mp, vector<string>& res) {
        if (index == s.size()) {
            curr.pop_back();
            res.push_back(curr);
        }

        string str = "";
        for (int i = index; i < s.size(); i++) {
            str.push_back(s[i]);

            if (mp[str] == true) {
                findHelper(i+1, s, curr + str + " ", mp, res);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        vector<string> res;

        for (string word: wordDict) {
            mp[word] = true;
        }

        findHelper(0, s, "", mp, res);
        return res;
    }
};

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
