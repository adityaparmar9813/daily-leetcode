class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> dp;
    unordered_map<int, int> index;

    int solve(vector<int>& arr, int i) {
        if (dp[i] != -1) return dp[i];

        long long ans = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0 && index.count(arr[i] / arr[j])) {
                ans = (ans + 1LL * solve(arr, j) * solve(arr, index[arr[i]/arr[j]]) % MOD) % MOD;
            }
        }

        return dp[i] = ans;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        dp.assign(arr.size(), -1);

        for (int i = 0; i < arr.size(); i++) index[arr[i]] = i;

        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            ans = (ans + solve(arr, i)) % MOD;
        }

        return ans;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)