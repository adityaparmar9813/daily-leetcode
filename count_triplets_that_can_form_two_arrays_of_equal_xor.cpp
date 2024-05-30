class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        
        for (int i = 0; i < n; i++) {
            int xor_sum = 0;

            for (int k = i; k < n; k++) {
                xor_sum ^= arr[k];

                if (xor_sum == 0) {
                    ans += (k-i);
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(1)
