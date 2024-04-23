class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) {
            vector<int> tmp;
            tmp.push_back(0);
            return tmp;
        }
        unordered_map<int, list<int>> adj;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> leaves;
        for(auto& d : adj) {
            if(d.second.size() == 1) {
                leaves.push_back(d.first);
            }
        }

        while(n > 2) {
            vector<int> new_leaves;
            n -= leaves.size(); 

            for(int leaf: leaves) {
                int neighbor = adj[leaf].front(); 
                adj[neighbor].remove(leaf); 
                
                if(adj[neighbor].size() == 1) {
                    new_leaves.push_back(neighbor); 
                }
            }
            leaves = new_leaves; 
        }
        return leaves;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
