class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) {
            return 0;
        }
        int a = 0, b = 1, c = 1;
        for(int i=4; i <= n+1; i++) {
            int ans = a+b+c;
            a = b;
            b = c;
            c = ans;
        }
        return c;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
