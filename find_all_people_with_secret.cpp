class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        adj[0].push_back({firstPerson, 0});
        adj[firstPerson].push_back({0, 0});
        for(auto meeting: meetings) {
            adj[meeting[0]].push_back({meeting[1], meeting[2]});
            adj[meeting[1]].push_back({meeting[0], meeting[2]});
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<int> time(n, INT_MAX);
        time[0] = 0;

        while(!q.empty()) {
            int curr = q.front().first;
            int curTime=q.front().second;
            q.pop();
            for(auto node: adj[curr]) {
                int v=node.first;
                int t=node.second;
                if(curTime <= t && t < time[v]) {
                    q.push({v, t});
                    time[v] = t;
                }
            }
        }

        vector<int> ans;
        for(int i=0; i < n; i++) {
            if(time[i] != INT_MAX) ans.push_back(i);
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)