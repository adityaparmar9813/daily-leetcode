class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (auto edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            if(curr == destination) {
                return true;
            }
            for(int node: adj[curr]){
                if(!visited[node]){
                    q.push(node);
                    visited[node]=true;
                }
            }
        }
        return false;
    }
};

// Time Complexity : O(N+E)
// Space Complexity : O(N+E)
