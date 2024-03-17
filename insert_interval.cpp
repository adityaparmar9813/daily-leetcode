class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, start = newInterval[0], end = newInterval[1];
        
        while(i < intervals.size() && intervals[i][1] < start) {
            ans.push_back(intervals[i++]);
        }
        
        while(i < intervals.size() && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i++][1]);    
        }
        ans.push_back({start, end});
        ans.reserve(ans.size()+intervals.size()-i);
        ans.insert(ans.end(), intervals.begin()+i, intervals.end());
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)