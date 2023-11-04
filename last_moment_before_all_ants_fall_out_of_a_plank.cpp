class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = 0;
        int minRight = INT_MAX;

        for(auto el: left) maxLeft = max(el, maxLeft);
        for(auto el: right) minRight = min(el, minRight);

        return max(maxLeft, n-minRight);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)