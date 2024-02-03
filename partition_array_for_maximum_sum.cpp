class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& arr, int index, int largest, int prev, int k) {
        largest = max(largest, arr[index]);

        if(index == arr.size()-1) return largest * (index-prev);
        if(prev != -1 && dp[prev][index] != -1) return dp[prev][index];

        int partition = INT_MIN, notPartition = INT_MIN;

        partition = largest * (index-prev) + solve(arr, index+1, 0, index, k);
        if(index-prev < k) notPartition = solve(arr, index+1, largest, prev, k);

        if(prev != -1) dp[prev][index] = max(partition, notPartition);
        return max(partition, notPartition);
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(), vector<int>(arr.size()+1, -1));
        return solve(arr, 0, 0, -1, k);
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
