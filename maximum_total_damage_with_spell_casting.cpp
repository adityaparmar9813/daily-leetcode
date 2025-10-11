class Solution {
   public:
	using ll = long long;

	ll solve(vector<pair<int, int>>& pCount, int index, vector<ll>& dp) {
		if (index >= pCount.size()) {
			return 0;
		}
		if (dp[index] != -1) {
			return dp[index];
		}

		int n = pCount.size(), nextIndex = index + 1;

		while (nextIndex < n &&
		       pCount[nextIndex].first <= pCount[index].first + 2) {
			nextIndex++;
		}
		ll take = 1LL * pCount[index].first * pCount[index].second +
		          solve(pCount, nextIndex, dp);
		ll notTake = solve(pCount, index + 1, dp);
		return dp[index] = max(take, notTake);
	}

	ll maximumTotalDamage(vector<int>& power) {
		int n = power.size();
		vector<pair<int, int>> pCount;
		sort(power.begin(), power.end());

		for (int i = 0; i < n; i++) {
			int count = 1;

			while (i + 1 < n && power[i] == power[i + 1]) {
				i++;
				count++;
			}
			pCount.push_back({power[i], count});
		}

		vector<ll> dp(pCount.size(), -1);
		return solve(pCount, 0, dp);
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)