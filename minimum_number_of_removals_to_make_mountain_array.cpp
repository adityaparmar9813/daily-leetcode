class Solution {
  public:
	int minimumMountainRemovals(vector<int> &nums) {
		vector<int> asc = vector<int>(nums.size(), 1);
		vector<int> desc = vector<int>(nums.size(), 1);

		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					asc[i] = max(asc[i], asc[j] + 1);
				}
			}
		}

		for (int i = nums.size() - 2; i > 0; i--) {
			for (int j = nums.size() - 1; j > i; j--) {
				if (nums[i] > nums[j]) {
					desc[i] = max(desc[i], desc[j] + 1);
				}
			}
		}

		int longest = 0;

		for (int i = 1; i < nums.size() - 1; i++) {
			if (asc[i] != 1 && desc[i] != 1) {
				longest = max(longest, asc[i] + desc[i] - 1);
			}
		}

		return nums.size() - longest;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n)