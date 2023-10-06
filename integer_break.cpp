class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n-1;
        if (n%3 == 0) return pow(3, n/3);
        else if (n%3 == 1) return 4 * pow(3, n/3-1);
        else return 2 * pow(3, n/3);
    }
};

// Time Complexity : O(1)
// Space Complexity : O(1)