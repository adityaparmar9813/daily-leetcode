class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, currBottles = 0;

        while (numBottles >= numExchange) {
            int newBottles = numBottles / numExchange;
            currBottles = numBottles % numExchange;
            numBottles = newBottles + currBottles;
            ans += newBottles;
        }
        return ans;
    }
};

// Time Complexity : O(log(n))
// Space Complexity : O(1)
