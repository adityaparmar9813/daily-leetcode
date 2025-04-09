class Solution {
   public:
	int minOperations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), greater<int>());
		int count = 0;

		if (nums.back() < k) {
			return -1;
		}

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[i - 1]) {
				count++;
			}
		}

		return count + (nums.back() != k);
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(1)