class Solution {
   public:
	long long countSubarrays(vector<int>& nums, long long k) {
		int n = nums.size();
		vector<long long> prefix(n + 1, 0);
		long long ans = 0;

		for (int i = 0; i < n; i++) {
			prefix[i + 1] = prefix[i] + nums[i];
		}

		for (int i = 0; i < n; i++) {
			int l = i, r = n;

			while (l < r) {
				int mid = l + (r - l) / 2;
				long long sum = prefix[mid + 1] - prefix[i];
				long long score = sum * (mid - i + 1);

				if (score < k) {
					l = mid + 1;
				} else {
					r = mid;
				}
			}
			ans += l - i;
		}
		return ans;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)