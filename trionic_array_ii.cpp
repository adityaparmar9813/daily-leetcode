class Solution {
   public:
	long long maxSumTrionic(vector<int>& nums) {
		int n = nums.size();
		long long INF = 2e15;

		vector<long long> inc1(n, -INF);
		vector<long long> dec(n, -INF);
		vector<long long> inc2(n, -INF);

		for (int i = 0; i < n; i++) {
			if (i > 0 && nums[i] > nums[i - 1]) {
				inc1[i] =
				    max((long long)nums[i - 1] + nums[i],
				        (inc1[i - 1] == -INF ? -INF : inc1[i - 1] + nums[i]));
			}

			if (i > 0 && nums[i] < nums[i - 1]) {
				if (dec[i - 1] != -INF)
					dec[i] = max(dec[i], dec[i - 1] + nums[i]);
				if (inc1[i - 1] != -INF)
					dec[i] = max(dec[i], inc1[i - 1] + nums[i]);
			}

			if (i > 0 && nums[i] > nums[i - 1]) {
				if (inc2[i - 1] != -INF)
					inc2[i] = max(inc2[i], inc2[i - 1] + nums[i]);
				if (dec[i - 1] != -INF)
					inc2[i] = max(inc2[i], dec[i - 1] + nums[i]);
			}
		}

		long long ans = -INF;
		for (int i = 0; i < n; i++) {
			ans = max(ans, inc2[i]);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)