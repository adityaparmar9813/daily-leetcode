class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=2; i < nums.size(); i=i+3) {
            if(nums[i]- nums[i-2] > k) return {};
            ans.push_back({nums[i-2], nums[i-1], nums[i]});
        }
        return ans;
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
