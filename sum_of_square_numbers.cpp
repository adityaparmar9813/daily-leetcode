class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<int, bool> mp;

        for (int i = 0; i <= sqrt(c); i++) {
            mp[i*i] = true;
        }

        for (int i = 0; i <= sqrt(c); i++) {
            if (mp.find(c - i*i) != mp.end()) {
                return true;
            }
        }
        return false;
    }
};

// Time Complexity : O(n ^ 1/2)
// Space Complexity : O(n ^ 1/2)
