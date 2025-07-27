class Solution {
   public:
	int countHillValley(vector<int>& nums) {
		int n = nums.size(), prev = nums[0], count = 0;
		vector<bool> diff = {0, 0};

		for (int i = 1; i < n; i++) {
			while (i < n && prev == nums[i]) {
				i++;
			}
			if (i == n) {
				break;
			}

			bool bigger = nums[i] > prev;
			diff[bigger] = 1;
			count += diff[bigger] && diff[!bigger];
			diff[!bigger] = 0;
			prev = nums[i];
		}
		return count;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)