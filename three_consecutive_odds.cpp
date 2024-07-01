class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int consecutiveOddCount = 0;

        for (int num: arr) {
            if (num % 2 == 0) {
                consecutiveOddCount = 0;
            } else {
                consecutiveOddCount++;

                if (consecutiveOddCount == 3) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
