class Solution {
public:
    vector<vector<int>> dp;
    int helper(int index, int total, vector<int>& cost, vector<int>& time) {
        if(total <= 0) return 0;
        if(index >= cost.size()) return 1e9;
        if(dp[index][total] != -1) return dp[index][total];

        int take = cost[index] + helper(index+1, total-time[index]-1, cost, time);
        int notTake =  0 + helper(index+1, total, cost, time);

        return dp[index][total] = min(take, notTake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        dp.resize(cost.size(), vector<int>(cost.size()+1, -1));
        return helper(0, cost.size(), cost, time);
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)