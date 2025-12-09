class Solution {
   public:
	int specialTriplets(vector<int>& nums) {
		const int mod = 1e9 + 7;
		int n = nums.size();

		unordered_map<long long, int> prefix;
		unordered_map<long long, int> suffix;

		for (int x : nums) {
			suffix[x]++;
		}

		long long ans = 0;

		for (int j = 0; j < n; j++) {
			long long x = nums[j];
			suffix[x]--;

			long long target = x * 2;

			long long left = 0;
			auto itL = prefix.find(target);
			if (itL != prefix.end()) {
				left = itL->second;
			}

			long long right = 0;
			auto itR = suffix.find(target);
			if (itR != suffix.end()) {
				right = itR->second;
			}

			ans = (ans + (left * right) % mod) % mod;

			prefix[x]++;
		}

		return (int)ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)