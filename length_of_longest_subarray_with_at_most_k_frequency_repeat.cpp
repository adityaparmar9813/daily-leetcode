class Solution {
   public:
	int maxSubarrayLength(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		int i = 0, j = 0, n = nums.size();
		int res = 0;

		while (j < n) {
			m[nums[j]]++;
			while (m[nums[j]] > k) {
				m[nums[i]]--;
				i++;
			}
			res = max(res, j - i + 1);
			j++;
		}
		return res;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)