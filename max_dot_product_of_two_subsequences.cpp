class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        // Base Case
        if (i < 0 || j < 0) return -1e9;

        if(dp[i][j] != -1) return dp[i][j];    
        
        // Recursive Case
        int take_both = nums1[i] * nums2[j] + max(0, solve(i-1, j-1, nums1, nums2));
        int take_p = solve(i-1, j, nums1, nums2);
        int take_pq = solve(i, j-1, nums1, nums2);

        return dp[i][j] = max(take_both, max(take_p, take_pq));
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        dp.resize(n, vector<int>(m, -1));
       
        int ans = solve(n-1, m-1, nums1, nums2);
        return ans;     
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)