class UnionFind {
    int n;
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        this->n = n;
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int Find(int u) {
        if (parent[u] != u) {
            parent[u] = Find(parent[u]);
        }
        return parent[u];
    }

    bool Union(int u, int v) {
        int rootU = Find(u);
        int rootV = Find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        }
        return false;
    }

    bool isConnected() {
        int root = Find(0);
        for (int i = 1; i < n; i++) {
            if (Find(i) != root) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind Alice(n), Bob(n);

        int edgesNeeded = 0;

        for (vector<int>& edge: edges) {
            int type = edge[0], u = edge[1]-1, v = edge[2]-1;
            if (type == 3) {
                if (Alice.Union(u, v) | Bob.Union(u, v)) {
                    edgesNeeded++;
                }
            }
        }

        for (vector<int>& edge: edges) {
            int type = edge[0], u = edge[1]-1, v = edge[2]-1;

            if (type == 1) {
                if (Alice.Union(u, v)) {
                    edgesNeeded++;
                }
            } else if (type == 2) {
                if (Bob.Union(u, v)) {
                    edgesNeeded++;
                }
            }
        }

        if (Alice.isConnected() && Bob.isConnected()) {
            return edges.size()-edgesNeeded;
        }
        return -1;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
