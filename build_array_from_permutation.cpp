class Solution {
   public:
	vector<int> buildArray(vector<int>& nums) {
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			nums[i] += 1000 * (nums[nums[i]] % 1000);
		}

		for (int i = 0; i < n; i++) {
			nums[i] /= 1000;
		}

		return nums;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)