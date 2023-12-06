class Solution {
public:
    int totalMoney(int n) {
        int prev_week = n / 7;
        int prev_week_amount = 28*prev_week + 7*prev_week*(prev_week-1)/2;

        int remaining_days = n % 7;
        int current_week_amount = 0;
        int start_amount = prev_week+1;
        for(int i=1; i <= remaining_days; i++) current_week_amount += start_amount++;

        return prev_week_amount + current_week_amount;
    }
};

// Time Complexity : O(1)
// Space Complexity : O(1)