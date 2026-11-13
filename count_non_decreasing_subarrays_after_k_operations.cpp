class Solution {
   public:
	long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
		int n = nums.size(), head = n, tail = n, r = n - 1;
		vector<int> starts(n);
		long long ans = 0, water = 0;
		for (int l = n - 1; l >= 0; --l) {
			int x = nums[l];
			while (head < tail && nums[starts[head]] <= x) {
				int s = starts[head++];
				int end = head < tail ? starts[head] : r + 1;
				water += 1LL * (x - nums[s]) * (end - s);
			}
			starts[--head] = l;
			while (water > k) {
				water -= nums[starts[tail - 1]] - nums[r];
				if (starts[tail - 1] == r) --tail;
				--r;
			}
			ans += r - l + 1;
		}
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)