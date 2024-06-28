class Solution {
public:
    static long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);

        for (auto& road: roads){
            deg[road[0]]++;
            deg[road[1]]++;
        }

        sort(deg.begin(), deg.end());
        long long ans=0;

        for (int i = 0; i < n; i++) {
            ans += (i + 1LL) * deg[i];   
        }
        return ans;
    }
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)
