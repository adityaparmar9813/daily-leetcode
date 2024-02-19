class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return ceil(log2(n)) == floor(log2(n));
    }
};

// Time Complexity : O(1)
// Space Complexity : O(1)