class Solution {
  public:
	int bitCount(int num) {
		int count = 0;

		while (num != 0) {
			count += (num % 2) == 1;
			num /= 2;
		}

		return count;
	}

	bool canSortArray(vector<int> &nums) {
		int n = nums.size();

		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < n - i - 1; ++j) {
				if (nums[j] > nums[j + 1] &&
					bitCount(nums[j]) == bitCount(nums[j + 1])) {
					swap(nums[j], nums[j + 1]);
				}
			}
		}

		for (int i = 0; i < n - 1; ++i) {
			if (nums[i] > nums[i + 1]) {
				return false;
			}
		}

		return true;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(1)