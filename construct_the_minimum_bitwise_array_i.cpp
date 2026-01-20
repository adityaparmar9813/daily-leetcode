class Solution {
   public:
	vector<int> minBitwiseArray(vector<int>& nums) {
		vector<int> res(nums.size());

		for (int i = 0; i < nums.size(); i++) {
			if (!(nums[i] & 1)) {
				res[i] = -1;
				continue;
			}
			int z = ((nums[i] + 1) & ~nums[i]) >> 1;
			res[i] = nums[i] & ~z;
		}

		return res;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)