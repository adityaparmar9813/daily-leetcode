class Solution {
   public:
	vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int mini = 1e9;

		for (int i = 1; i < nums.size(); i++) {
			mini = min(mini, nums[i] - nums[i - 1]);
		}

		vector<vector<int>> ans;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] - nums[i - 1] == mini) {
				ans.push_back({nums[i - 1], nums[i]});
			}
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)