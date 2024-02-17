class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < heights.size()-1; i++) {
            int diff = heights[i+1]-heights[i];
            
            if(diff > 0) {
                pq.push(diff);
                if (pq.size() > ladders) {
                    int smallest_diff = pq.top();
                    pq.pop();
                    bricks -= smallest_diff;
                    if (bricks < 0) return i;
                }
            }
        }
        return heights.size() - 1;
    }
};

// Time Complexity : o(n*log(n))
// Space Complexity : O(n)