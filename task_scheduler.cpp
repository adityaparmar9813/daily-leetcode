class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size(), mostFreq = INT_MIN, mostFreqQuantity = 0;
        vector<int> freqs(26, 0);

        for (auto task: tasks) freqs[task-'A']++;
        for (auto n: freqs) {
            if (n == mostFreq) mostFreqQuantity++;
            else if (n > mostFreq) {
                mostFreq = n;
                mostFreqQuantity = 1;
            }
        }
        return max(len, (mostFreq-1) * (n+1) + mostFreqQuantity);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)