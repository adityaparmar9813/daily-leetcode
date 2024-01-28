class Solution {
    public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();

        for(int left=0; left < m; left++) {
            vector<int> prefix(n, 0);
            for(int right = left ; right < m ; right++) {
                for(int i=0; i < n; i++) prefix[i] += matrix[i][right];

                for(int i = 0 ; i<n;i++) {
                    int sum = 0;

                    for(int j=i; j < n; j++) {
                        sum += prefix[j];
                        if(sum == target) ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(n^3)
// Space Complexity : O(n)  
