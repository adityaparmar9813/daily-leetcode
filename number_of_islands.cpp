class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited.count({i, j})) {
                    q.push({i, j});
                    visited.insert({i, j});
                    ans++;

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        if (x > 0 && grid[x-1][y] == '1' && !visited.count({x-1, y})) {
                            q.push({x-1, y});
                            visited.insert({x-1, y});
                        }
                        if (x < m-1 && grid[x+1][y] == '1' && !visited.count({x+1, y})) {
                            q.push({x+1, y});
                            visited.insert({x+1, y});
                        }
                        if (y > 0 && grid[x][y-1] == '1' && !visited.count({x, y-1})) {
                            q.push({x, y-1});
                            visited.insert({x, y-1});
                        }
                        if (y < n-1 && grid[x][y+1] == '1' && !visited.count({x, y+1})) {
                            q.push({x, y+1});
                            visited.insert({x, y+1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(m*n)
// Space Complexity : O(m*n)
