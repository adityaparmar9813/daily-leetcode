class Solution {
   public:
	bool check(vector<int>& nums) {
		int count = 0, n = nums.size();

		for (int i = 0; i < n; i++) {
			if (nums[i] > nums[(i + 1) % n]) {
				count++;
			}
		}

		return count <= 1;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)