class Solution {
   public:
	int partitionArray(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int start = nums[0], ans = 1;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] - start > k) {
				start = nums[i];
				ans++;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(1)