class Solution {
   public:
	int minimumOperations(vector<int>& nums) {
		int n = nums.size();

		for (int ops = 0; ops * 3 <= n; ++ops) {
			vector<int> freq(101, 0);
			bool hasDuplicate = false;

			for (int i = ops * 3; i < n; ++i) {
				if (++freq[nums[i]] > 1) {
					hasDuplicate = true;
					break;
				}
			}

			if (!hasDuplicate) {
				return ops;
			}
		}

		return (n + 2) / 3;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)