class Graph {
public:
    map<int, vector<pair<int, int>>> mp; 
    int n;
    Graph(int m, vector<vector<int>>& edges) {
        n = m;
        for(int i = 0; i < edges.size(); i++) {
            mp[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        mp[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<bool> visited(n, false);
        vector<int> ans(n, 1e8); 
        ans[node1]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, node1}); 
        while(pq.empty() == false) {
            auto p = pq.top();
            pq.pop();
            int u = p.second;
            visited[u]=true;

            for(auto node: mp[u]) {
                int v = node.first;
                int wt = node.second;
                if(visited[v] == false && ans[v] > ans[u]+wt) {
                    ans[v] = ans[u]+wt;
                    pq.push({ans[v], v});
                }
            }
        }
        return ans[node2] >= 1e8 ? -1 : ans[node2];
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)