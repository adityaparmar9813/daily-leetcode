class Solution {
public:
    int n, distanceThreshold;
    vector<vector<int>> dist;
    
    void floyd_warshall(vector<vector<int>>& edges) {
        dist.assign(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        for (auto edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (w <= distanceThreshold) {
                dist[u][v] = dist[v][u] = w;
            }
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        this->n = n;
        this->distanceThreshold = distanceThreshold;
        floyd_warshall(edges);
        
        int mini = n, city = -1;
        
        for (int i = 0; i < n; i++) {
            int count = -1; 
            
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= mini) {
                mini = count;
                city = i;
            }
        }
        return city;
    }
};

// Time Complexity : O(n ^ 3)
// Space Complexity : O(n ^ 2)
