class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for (int i = 0; i < logs.size(); ++i) {
            if (logs[i][0] != '.') {
                depth++;
            } else if (depth != 0 && logs[i].size() == 3) {
                depth--;
            }
        }
        return depth;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
