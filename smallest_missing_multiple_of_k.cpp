class Solution {
   public:
	int missingMultiple(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int curr = k;

		for (int num : nums) {
			if (num == curr) {
				curr += k;
			}
			if (num > curr) {
				return curr;
			}
		}

		return curr;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(1)