class Solution {
public:
    bool canAliceWin(int n) {
        vector<int> range(10);
        range[0] = 10;

        for (int i = 1; i < 10; i++) {
            range[i] = range[i - 1] + (10 - i);
        }

        int it = upper_bound(range.begin(), range.end(), n) - range.begin();
        return (it  %  2);
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)