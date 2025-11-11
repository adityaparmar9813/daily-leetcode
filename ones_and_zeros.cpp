class Solution {
   public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int sz = strs.size();
		vector<pair<int, int>> cnt(sz);

		for (int i = 0; i < sz; ++i) {
			int zeros = count(strs[i].begin(), strs[i].end(), '0');
			int ones = strs[i].size() - zeros;
			cnt[i] = {zeros, ones};
		}

		vector<vector<vector<int>>> dp(
		    sz, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
		return solve(0, m, n, cnt, dp);
	}

   private:
	int solve(int i, int zerosLeft, int onesLeft,
	          const vector<pair<int, int>>& cnt,
	          vector<vector<vector<int>>>& dp) {
		if (i == cnt.size()) {
			return 0;
		}
		if (dp[i][zerosLeft][onesLeft] != -1) {
			return dp[i][zerosLeft][onesLeft];
		}

		int notTake = solve(i + 1, zerosLeft, onesLeft, cnt, dp);
		int take = 0;

		if ((zerosLeft >= cnt[i].first) && (onesLeft >= cnt[i].second)) {
			take = 1 + solve(i + 1, zerosLeft - cnt[i].first,
			                 onesLeft - cnt[i].second, cnt, dp);
		}
		return dp[i][zerosLeft][onesLeft] = max(take, notTake);
	}
};

// Time Complexity : O(n ^ 3)
// Space Complexity : O(n ^ 3)