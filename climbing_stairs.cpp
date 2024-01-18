class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;

        int a = 1, b = 2;
        for(int i=n-3; i >= 0; i--) {
            int temp = a+b;
            a = b;
            b = temp;
        }
        return b;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
