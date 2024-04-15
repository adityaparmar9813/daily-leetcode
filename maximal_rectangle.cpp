class Solution {
public:
    vector<vector<int>> mt;
    int maximalRectangle(vector<vector<char>>& matrix) {
        mt = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        int ans = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    mt[i][j] = 1, ans = 1;
                } else {
                    mt[i][j] = 0;
                } 
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            ans = max(ans, mt[i][0]);

            for (int j = 1; j < matrix[i].size(); j++) {
                if (mt[i][j] == 1) {
                    mt[i][j] += mt[i][j - 1];
                    ans = max(ans, mt[i][j]);
                } else {
                    ans = max(ans, mt[i][j - 1]);
                }
            }
        }
        
        for (int i = 0; i < mt.size(); i++) {
            for (int j = 0; j < mt[i].size(); j++) {
                if (mt[i][j] == 0) {
                    continue;   
                }
                int n = 1, mn = mt[i][j];

                for (int r = i + 1; r < matrix.size(); r++) {
                    if (mt[r][j] == 0) break;
                    mn = min(mn, mt[r][j]);
                    n++;
                    ans = max(ans, n * mn);
                }
            }
        }
        return ans;
    }
};


// Time Complexity : O(n*m)
// Space Complexity : O(n*m)
