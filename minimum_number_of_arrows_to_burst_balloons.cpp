class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int lower = points[0][0], upper = points[0][1];
        int ans = 1;

        for(int i=1; i < points.size(); i++) {
            if((points[i][0] >= lower && points[i][0] <= upper) || (points[i][1] <= upper && points[i][1] >= lower)) {
                lower = max(points[i][0], lower);
                upper = min(points[i][1], upper);
            }
            else {
                lower = points[i][0];
                upper = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)