class Solution {
public:
    int passThePillow(int n, int time) {
        int cycleCount = time / (n-1);
        bool direction = cycleCount % 2 == 0;

        if (direction == true) {
            return 1 + (time % (n-1));
        }
        return n - (time % (n-1));
    }
};

// Time Complexity : O(1)
// Space Complexity : O(1)