class Solution {
   public:
	long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
	                           int k2) {
		int n = nums1.size(), M = 0;
		long long k = 1LL * k1 + k2;
		vector<int> diff(n);

		for (int i = 0; i < n; i++) {
			M = max(M, diff[i] = abs(nums1[i] - nums2[i]));
		}

		vector<int> bucket(M + 1);
		for (int x : diff) {
			bucket[x]++;
		}

		for (int i = M; i > 0 && k > 0; i--) {
			int take = min((long long)bucket[i], k);
			bucket[i] -= take;
			bucket[i - 1] += take;
			k -= take;
		}

		long long ans = 0;
		for (int i = 1; i <= M; i++) {
			ans += 1LL * bucket[i] * i * i;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)