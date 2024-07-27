class Solution {
public:
    void dijkstra(int src,vector<vector<int>> &adj,vector<vector<long long>> &dist){
        priority_queue<pair<int,int>> pq;
        dist[src][src] = 0;
        pq.push({0, src});
        pair<long long, int> curr;

        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();

            for (int i = 0; i < 26; i++) {
                if (adj[curr.second][i] != INT_MAX && (-1 * curr.first) + adj[curr.second][i] < dist[src][i]) {
                    dist[src][i]= (long long)((-1*curr.first) + adj[curr.second][i]);
                    pq.push({-1*dist[src][i], i});
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> adj(26,vector<int> (26, INT_MAX));
        int n = original.size();
        
        for (int i = 0; i < n; i++) {
            adj[original[i]-'a'][changed[i]-'a'] = min(adj[original[i]-'a'][changed[i]-'a'], cost[i]);
        }

        vector<vector<long long>> dist(26,vector<long long> (26,INT_MAX));
        for (int i = 0; i < 26; i++) {
            dijkstra(i, adj, dist);
        }

        long long res = 0;
        for (int i = 0; i < source.length(); i++) {
            if (dist[source[i]-'a'][target[i]-'a'] == INT_MAX) {
                return -1;
            }
            res += dist[source[i]-'a'][target[i]-'a'];
        }
        return res;
    }
};

// Time Complexity : O(n ^ 2 * log(n))
// Space Complexity : O(n ^ 2)
