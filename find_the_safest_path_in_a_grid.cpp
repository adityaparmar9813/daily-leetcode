class Solution {
public:
    int arr[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isvalid(int r,int c,int n){
        return r >= 0 && c >= 0 && r < n && c < n;
    }

    bool dfs(int r, int c, int n, vector<vector<bool>>& visited, vector<vector<int>>& mh, int mid) {
        if(r == n-1 && c == n-1) {
            return mh[r][c] >= mid;
        }
        if (mh[r][c] < mid) {
            return false;
        }
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + arr[i][0];
            int nc = c + arr[i][1];
            if(isvalid(nr,nc,n) && !visited[nr][nc] && mh[nr][nc]>=mid){
                if(dfs(nr,nc,n,visited,mh,mid)){
                    return true;
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] || grid[n-1][n-1]) {
            return 0;
        }

        vector<vector<int>> manhattan(n, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1){
                    q.push({{i, j}, 0});
                    manhattan[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + arr[i][0];
                int nc = c + arr[i][1];
                if (isvalid(nr, nc, n) && manhattan[nr][nc] == -1){
                    q.push({{nr, nc}, d + 1});
                    manhattan[nr][nc] = d + 1;
                }
            }
        }
        
        int s = 0, e = 500;
        while (s <= e) {
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            int mid = (s + e) / 2;

            if (dfs(0, 0, n, visited, manhattan, mid)) {
                s = mid+1;
            }
            else {
                e = mid-1;
            }
        }
        return e;
    }
};

// Time Complexity: O(n^2 * log(n))
// Space Complexity: O(n^2)
