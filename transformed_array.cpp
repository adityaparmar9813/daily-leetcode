class Solution {
   public:
	inline int negativeMod(int num, int denom) {
		return ((num % denom) + denom) % denom;
	}

	vector<int> constructTransformedArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n, 0);

		for (int i = 0; i < n; i++) {
			if (nums[i] > 0) {
				res[i] = nums[(i + nums[i]) % n];
			} else if (nums[i] < 0) {
				res[i] = nums[negativeMod(i + nums[i], n)];
			}
		}

		return res;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)