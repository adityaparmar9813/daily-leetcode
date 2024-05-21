class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr, int index, vector<vector<int>>& ans) {
        ans.push_back(curr);

        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            solve(nums, curr, i+1, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;

        solve(nums, curr, 0, ans);
        return ans;
    }
};

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
