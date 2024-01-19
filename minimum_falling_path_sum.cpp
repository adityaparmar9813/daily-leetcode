class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;

        for(int i=1; i < matrix.size(); i++) {
            for(int j=0; j < matrix[0].size(); j++) {
                int curr = matrix[i-1][j];
                if(j != 0) curr = min(curr, matrix[i-1][j-1]);
                if(j != matrix[0].size()-1) curr = min(curr, matrix[i-1][j+1]);
                matrix[i][j] += curr;
            }
        }

        for(int i=0; i < matrix[0].size(); i++) {
            ans = min(ans, matrix[matrix.size()-1][i]);
        }
        return ans;
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
