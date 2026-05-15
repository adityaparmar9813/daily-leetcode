class Solution {
   public:
	int search(vector<int>& nums, int l, int r) {
		if (nums[l] <= nums[r]) {
			return -1;
		}

		if (r - l == 1) {
			return r;
		}

		int mid = l + (r - l) / 2;

		int left = search(nums, l, mid);
		int right = search(nums, mid + 1, r);

		if (left == -1 && right == -1) {
			return mid + 1;
		}

		return max(left, right);
	}

	int findMin(vector<int>& nums) {
		int idx = search(nums, 0, nums.size() - 1);
		return idx == -1 ? nums[0] : nums[idx];
	}
};

// Time Complexity: O(log(n))
// Space Complexity: O(log(n))