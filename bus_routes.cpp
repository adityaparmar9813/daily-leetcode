class Solution {
public:
    int n;
    vector<bool> isTarget;
    vector<vector<int>> adj;
    vector<unordered_set<int>> bus;

    void bus_set(vector<vector<int>>& routes) {
        bus.resize(n);
        int i = 0;
        for(auto r: routes) {
            bus[i++] = unordered_set<int>(r.begin(), r.end());
        }
    }

    bool check_intersect(const unordered_set<int>& busX, const unordered_set<int>& busY) {
        for (int x: busX) if (busY.count(x)) return 1;

        return 0;
    }

    void make_adj(vector<unordered_set<int>>& bus) {
        adj.resize(n);
        for(int i=0; i < n-1; i++){
            for(int j=i+1; j < n; j++){
                if (check_intersect(bus[i], bus[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }

    void source_target(int source, int target, queue<int>& q, vector<int>&  dist) {
        isTarget.assign(n, 0);
        for(int i = 0; i < n; i++){
            if (bus[i].count(source)){
                q.push(i);
                dist[i]=1;
            }
            if (bus[i].count(target)) isTarget[i] = 1;
        }
    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        n = routes.size();
        bus_set(routes);     
        make_adj(bus);

        queue<int> q;
        vector<int> dist(n, n+1);
        source_target(source, target, q, dist);

        while(!q.empty()){
            int x = q.front();
            int ans = dist[x];
            q.pop();
            if (isTarget[x]) return ans;

            for(int y: adj[x]){
                if(dist[y] > ans+1){
                    dist[y] = ans+1;
                    q.push(y);
                }
            }
        }
        return -1;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)