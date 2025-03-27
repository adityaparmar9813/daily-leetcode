class Solution {
   public:
	int minimumIndex(vector<int>& nums) {
		int num = 0, count = 0, size = nums.size();

		for (int n : nums) {
			if (count == 0) {
				num = n;
				count = 1;
			} else if (n == num) {
				count++;
			} else {
				count--;
			}
		}

		int totalCount =
		    count_if(nums.begin(), nums.end(), [&](int n) { return n == num; });
		int leftCount = 0;

		for (int i = 0; i < size - 1; i++) {
			if (nums[i] == num) {
				leftCount++;
			}

			if (leftCount > (i + 1) / 2 &&
			    (totalCount - leftCount) > (size - i - 1) / 2) {
				return i;
			}
		}

		return -1;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)