class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a, b = cost[n-1], c = 0;

        for(int i=n-2; i>=0; i--) {
            a = cost[i] + min(b, c);
            c = b;
            b = a;

        }
        return min(b, c);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)