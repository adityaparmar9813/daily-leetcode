
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;

        int calc = floor(log2(n));
        int count = (1 << calc+1) - 1;
        return count - minimumOneBitOperations(n ^ (1 << calc));
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)