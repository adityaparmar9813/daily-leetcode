class Solution {
  public:
	vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
		int xorSum = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			xorSum ^= nums[i];
		}

		int maxi = pow(2, maximumBit) - 1;
		vector<int> ans = {xorSum ^ maxi};

		for (int i = nums.size() - 1; i > 0; i--) {
			xorSum ^= nums[i];
			ans.push_back(xorSum ^ maxi);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)