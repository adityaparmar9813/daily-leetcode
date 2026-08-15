class Solution {
   public:
	int longestSubsequence(vector<int>& nums) {
		int totalXor = 0;
		bool hasNonZero = false;

		for (int x : nums) {
			totalXor ^= x;

			if (x != 0) {
				hasNonZero = true;
			}
		}

		if (!hasNonZero) {
			return 0;
		}
		if (totalXor != 0) {
			return nums.size();
		}

		return nums.size() - 1;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)