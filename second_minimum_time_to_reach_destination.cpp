class Solution {
public:

    int solve(int step, int time, int change) {
        int ans=0;

        for(int i=0; i < step; i++) {
            int gr = ans / change;

            if (gr & 1) {
                ans = (gr + 1) * change;
            }
            ans += time;
        }
        return ans;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);

        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> dist(n+1, INT_MAX), dist2(n+1, INT_MAX);
        queue<pair<int, int>> pq;
        pq.emplace(1, 0);
        dist[1] = 0;

        while (!pq.empty()) {
            auto [x, d] = pq.front();
            pq.pop();

            for (int y : adj[x]) {
                int curr = d+1;

                if (curr < dist[y]) {
                    dist2[y] = dist[y];
                    dist[y] = curr;
                    pq.emplace(y, curr);
                } 
                else if (curr > dist[y] && curr < dist2[y]) {
                    dist2[y] = curr;
                    pq.emplace(y, curr);
                }
            }
        }

        int steps = dist2[n];
        if (steps == INT_MAX) {
            return -1;
        }
        return solve(steps, time, change);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
