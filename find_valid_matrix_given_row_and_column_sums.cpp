class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> matrix(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rowSum[i] < colSum[j]) {
                    matrix[i][j] = rowSum[i];
                } else {
                    matrix[i][j] = colSum[j];
                }
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }
        return matrix;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)
