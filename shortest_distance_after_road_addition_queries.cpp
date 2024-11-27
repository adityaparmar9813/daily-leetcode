
class Solution {
  public:
	vector<int> shortestDistanceAfterQueries(int n,
											 vector<vector<int>> &queries) {
		vector<int> ans;
		unordered_map<int, vector<int>> mp;

		for (int i = 0; i < n - 1; ++i) {
			mp[i].push_back(i + 1);
		}

		for (auto &it : queries) {
			mp[it[0]].push_back(it[1]);

			vector<int> dp(n, INT_MAX);
			dp[n - 1] = 0;

			for (int i = n - 2; i >= 0; --i) {
				for (int next : mp[i]) {
					dp[i] = min(dp[i], 1 + dp[next]);
				}
			}

			ans.push_back(dp[0]);
		}

		return ans;
	}
};

// Time Complexity: O(n * q)
// Space Complexity: O(n)