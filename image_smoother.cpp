class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int sum = 0, count = 0;

                for (int x = max(0, i-1); x < min(rows, i+2); x++) {
                    for (int y = max(0, j-1); y < min(cols, j+2); y++) {
                        sum += img[x][y];
                        count += 1;
                    }
                }
                result[i][j] = sum / count;
            }
        }
        return result;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)