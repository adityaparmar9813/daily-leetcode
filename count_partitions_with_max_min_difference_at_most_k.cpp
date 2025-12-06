class Solution {
   public:
	const int MOD = 1e9 + 7;

	int countPartitions(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> pre(n + 1), ans(n + 1);
		pre[0] = ans[0] = 1;

		deque<int> dqmx, dqmn;
		int wmax = 1;

		for (int i = 1; i <= n; ++i) {
			int idx = i - 1;

			while (!dqmx.empty() && nums[dqmx.back()] <= nums[idx]) {
				dqmx.pop_back();
			}
			dqmx.push_back(idx);

			while (!dqmn.empty() && nums[dqmn.back()] >= nums[idx]) {
				dqmn.pop_back();
			}
			dqmn.push_back(idx);

			while (wmax <= i && nums[dqmx.front()] - nums[dqmn.front()] > k) {
				if (dqmx.front() == wmax - 1) {
					dqmx.pop_front();
				}
				if (dqmn.front() == wmax - 1) {
					dqmn.pop_front();
				}
				++wmax;
			}

			int total = pre[i - 1];
			int sub = (wmax >= 2 ? pre[wmax - 2] : 0);
			ans[i] = (total - sub + MOD) % MOD;
			pre[i] = (pre[i - 1] + ans[i]) % MOD;
		}

		return ans[n];
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)