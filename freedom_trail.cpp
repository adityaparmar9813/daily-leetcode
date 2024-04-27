class Solution {
public:
    vector<vector<int>> dp;
    int solve(int index, int dial_index, string& ring, string& key, int m) {
        if(index >= m) {
            return 0;
        }
        if(dp[index][dial_index] != -1) {
            return dp[index][dial_index];
        }
        int ans = 1e9;

        for(int k = 0; k < ring.size(); k++) {
            int i = (index + k) % ring.size();

            if(ring[i] == key[index]) {
                int clockwise = abs(i - dial_index);
                int anticlockwise = ring.size() - abs(i - dial_index);

                ans = min(ans , min(clockwise, anticlockwise) + 1 + solve(index+1, i, ring, key, m));
            }
        }
        return dp[index][dial_index] = ans;
    }
    int findRotateSteps(string ring, string key) {
        dp.resize(105, vector<int>(105, -1));
        return solve(0, 0, ring, key, key.size());
    }
};

// Time Complexity : O(n^2 * m)
// Space Complexity : O(n^2)
