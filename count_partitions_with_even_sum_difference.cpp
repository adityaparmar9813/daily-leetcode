class Solution {
   public:
	int countPartitions(vector<int>& nums) {
		if (accumulate(nums.begin(), nums.end(), 0) % 2 == 0) {
			return nums.size() - 1;
		}
		return 0;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)