class Solution {
   public:
	long long countSubarrays(vector<int>& nums, int k) {
		int l = 0, r = 0, n = nums.size(), count = 0;
		long long ans = 0;
		int maxi = *max_element(nums.begin(), nums.end());

		while (r < n) {
			count += nums[r] == maxi;

			while (count == k) {
				ans += (n - r);
				count -= nums[l++] == maxi;
			}

			r++;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)