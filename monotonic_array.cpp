class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int monotone = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - nums[i-1];

            if (diff > 0) {
                if (monotone == -1) return false;
                monotone = 1;
            }
            if (diff < 0) {
                if (monotone == 1) return false;
                monotone = -1;
            }
        }
        return true;
    }
};