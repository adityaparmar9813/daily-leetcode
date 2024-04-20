class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& a, vector<vector<int>>& v, int &bottom, int &right) {
        v[i][j] = 1;

        if (i+1 < a.size() && a[i+1][j] == 1 && v[i+1][j] == 0) {
            bottom = max(bottom, i+1);
            dfs(i+1, j, a, v, bottom, right);
        }
        
        if (j+1 < a[0].size() && a[i][j+1] == 1 && v[i][j+1] == 0) {
            right = max(right, j+1);
            dfs(i, j+1, a, v, bottom, right);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& a) {
        vector<vector<int>> v(a.size(), vector<int>(a[0].size(), 0));
        vector<vector<int>> ans;
        int i, j;

        for (i = 0; i < a.size(); i++) {
            for (j = 0; j < a[0].size(); j++) {
                if (!v[i][j] && a[i][j] == 1) {
                    int top = i, left = j, bottom = i, right = j;
                    dfs(i, j, a, v, bottom, right);

                    ans.push_back({top, left, bottom, right});
                }
                
            }
        }
        return ans;
    }
};

// Time Complexity : O(n*m)
// Space Complexity : O(n*m)
