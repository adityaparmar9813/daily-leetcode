class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> prev_mp(26, 0), mp(26, 0);
        vector<string> ans;

        for (int i = 0; i < words[0].size(); i++) {
            prev_mp[words[0][i] - 'a']++;
        }

        for (int i = 0; i < words.size(); i++) {
            for (char ch: words[i]) {
                mp[ch - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                prev_mp[i] = min(prev_mp[i], mp[i]);
                mp[i] = 0;
            }
        }

        for (int i = 0; i < 26; i++) {
            while (prev_mp[i] > 0) {
                ans.push_back(string(1, i + 'a'));
                prev_mp[i]--;
            }
        }
        return ans;
    }
};

// Time Complexity : O(n*m)
// Space Complexity : O(1)
