class Solution {
  public:
	int longestSubarray(vector<int> &nums) {
		int n = nums.size(), ans = 0;
		int maxi = *max_element(nums.begin(), nums.end());

		for (int i = 0; i < n; i++) {
			int count = 0;

			while (i < n && nums[i] == maxi) {
				count++;
				i++;
			}
			ans = max(ans, count);
		}
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)