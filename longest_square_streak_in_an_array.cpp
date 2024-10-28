class Solution {
  public:
	unordered_map<int, int> dp;

	int solve(unordered_map<long long, bool> &mp, int num) {
		if (dp.find(num) != dp.end()) {
			return dp[num];
		}

		long long square = num * 1LL * num;
		if (mp.find(square) != mp.end()) {
			return dp[num] = 1 + solve(mp, square);
		}

		return dp[num] = 1;
	}

	int longestSquareStreak(vector<int> &nums) {
		int ans = 0;
		unordered_map<long long, bool> mp;

		for (int num : nums) {
			mp[num] = true;
		}

		for (const auto &[val, _] : mp) {
			ans = max(ans, solve(mp, val));
		}

		return ans == 1 ? -1 : ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)