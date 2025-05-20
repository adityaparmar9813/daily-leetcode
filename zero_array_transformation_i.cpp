class Solution {
   public:
	bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
		vector<int> sweep(nums.size() + 1, 0);

		for (const auto& query : queries) {
			sweep[query[0]] -= 1;
			sweep[query[1] + 1] += 1;
		}

		int curr = 0;

		for (int i = 0; i < nums.size(); i++) {
			curr += sweep[i];

			if (nums[i] + curr > 0) {
				return false;
			}
		}

		return true;
	}
};

// Time Complexity : O(n + m)
// Space Complexity : O(n)