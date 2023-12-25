class Solution {
public:
    vector<int> answers;
    
    int helper(int i, const string &s) {
        if (i >= s.size()) return 1;
        if (s[i] == '0') return 0;
        if (answers[i] > -1) return answers[i];

        int ans = 0;

        if(s.size()-i >= 2) {
            if(stoi(s.substr(i, 2)) <= 26) ans = helper(i+2, s);
        }
        return answers[i] = ans + helper(i+1, s);
    }

    int numDecodings(string s) {
        answers.resize(s.size(), -1);
        return helper(0, s);
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)