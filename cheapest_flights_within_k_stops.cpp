class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        while(!q.empty()) {
            pair<int, pair<int, int>> curr = q.front();
            q.pop();
            int cost = curr.first;
            int node = curr.second.first;
            int stops = curr.second.second;
            
            for(auto curr: adj[node]) {
                int adjNode = curr.first;
                int price = curr.second;
                
                if(stops <= k && cost+price < dist[adjNode]) {
                    dist[adjNode] = cost + price;
                    q.push({cost+price, {adjNode, stops+1}});
                }
            }
            
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)