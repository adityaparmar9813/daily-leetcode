class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime = 0;
        long long totalWaitTime = 0;

        for (auto customer: customers) {         
            currentTime = max(currentTime, customer[0]) + customer[1];
            totalWaitTime += (currentTime - customer[0]);
        }
        return (double)totalWaitTime / customers.size();
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
