class Solution {
  public:
	int maximumBeauty(vector<int> &nums, int k) {
		vector<long long> mp(1e6, 0);
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			mp[nums[i] - k + 100000] += 1;
			mp[nums[i] + k + 1 + 100000] -= 1;
		}

		long long curr = mp[0];
		for (int i = 1; i < mp.size(); i++) {
			curr += mp[i];
			mp[i] = curr;
		}

		int ans = 0;
		for (int i = 0; i < mp.size(); i++) {
			ans = max(ans, (int)mp[i]);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)