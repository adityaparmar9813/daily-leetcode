class Solution {
   public:
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		int n = nums.size();
		vector<int> ans(n);
		int j = 0, count = 0;

		for (int i = 0; i < n; i++) {
			if (nums[i] < pivot) {
				ans[j++] = nums[i];
			} else if (nums[i] == pivot) {
				count++;
			}
		}

		while (count--) {
			ans[j++] = pivot;
		}

		for (int i = 0; i < n; i++) {
			if (nums[i] > pivot) {
				ans[j++] = nums[i];
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)