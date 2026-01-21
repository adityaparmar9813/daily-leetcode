class Solution {
   public:
	vector<int> minBitwiseArray(vector<int>& nums) {
		vector<int> ans(nums.size());

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 2) {
				ans[i] = -1;
				continue;
			}

			int numCopy = nums[i];
			int count = 0;

			while ((nums[i] & 1) == 1) {
				count++;
				nums[i] >>= 1;
			}

			ans[i] = numCopy - (1 << (count - 1));
		}
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)