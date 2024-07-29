class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), ans = 0;
        vector<int> smallerRightCount(n, 0);
        vector<int> largerLeftCount(n, 0);
        vector<int> smallerLeftCount(n, 0);
        vector<int> largerRightCount(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j < i) {
                    if (rating[j] > rating[i]) {
                        largerLeftCount[i]++;
                    } else if (rating[j] < rating[i]) {
                        smallerLeftCount[i]++;
                    }
                } else {
                    if (rating[j] > rating[i]) {
                        largerRightCount[i]++;
                    } else if (rating[j] < rating[i]) {
                        smallerRightCount[i]++;
                    }
                }
            }
            ans += smallerRightCount[i] * largerLeftCount[i];
            ans += largerRightCount[i] * smallerLeftCount[i];
        }
        return ans;
    }
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n)
