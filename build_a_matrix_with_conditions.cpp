class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        if (orderRows.empty() or orderColumns.empty()) {
            return {};
        }
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }

    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n + 1);
        vector<int> order;
        vector<int> visited(n + 1, 0);
        bool hasCycle = false;

        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, order, hasCycle);
                if (hasCycle) return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& order, bool& hasCycle) {
        visited[node] = 1;
        for (int neighbor: adj[node]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, adj, visited, order, hasCycle);
                if (hasCycle) {
                    return;
                }
            } else if (visited[neighbor] == 1) {
                hasCycle = true;
                return;
            }
        }
        visited[node] = 2;
        order.push_back(node);
    }
};

// Time Complexity : O(k^2)
// Space Complexity : O(k)
