class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n);
        vector<vector<int>> ans(n);

        for (auto& edge: edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
        }

        for (int ancestor = 0; ancestor < n; ancestor++) {
            queue<int> q;
            q.push(ancestor);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int child: adjacencyList[curr]) {
                    if (ans[child].size() == 0 || ans[child].back() != ancestor) {
                        ans[child].push_back(ancestor);
                        q.push(child);
                    }
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)
