class Solution {
   public:
	int search(vector<int>& nums, int l, int r) {
		if (l == r) {
			return l;
		}
		if (nums[l] < nums[r]) {
			return l;
		}
		if (r - l == 1) {
			return nums[l] <= nums[r] ? l : r;
		}

		int mid = l + (r - l) / 2;

		if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
			int left = search(nums, l, mid);
			int right = search(nums, mid + 1, r);

			return nums[left] <= nums[right] ? left : right;
		}

		int left = search(nums, l, mid);
		int right = search(nums, mid + 1, r);

		return nums[left] <= nums[right] ? left : right;
	}

	int findMin(vector<int>& nums) {
		return nums[search(nums, 0, nums.size() - 1)];
	}
};

// Time Complexity: O(log(n))
// Space Complexity: O(log(n))