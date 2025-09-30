class Solution {
   public:
	int triangularSum(vector<int>& nums) {
		int n = nums.size();
		vector<int> curr = nums, next(n);

		for (int size = n; size > 1; --size) {
			for (int i = 0; i < size - 1; i++) {
				next[i] = (curr[i] + curr[i + 1]) % 10;
			}
			curr.swap(next);
		}

		return curr[0];
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n)