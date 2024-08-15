class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int extra5 = 0, extra10 = 0;

        for (int bill: bills) {
            if (bill == 5) {
                extra5++;
            } else if (bill == 10) {
                if (extra5 > 0) {
                    extra5--;
                    extra10++;
                } else {
                    return false;
                }
            } else {
                if (extra10 > 0 && extra5 > 0) {
                    extra5--;
                    extra10--;
                } else if (extra5 > 2) {
                    extra5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
