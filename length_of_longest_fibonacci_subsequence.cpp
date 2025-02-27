class Solution {
   public:
	unordered_map<int, int> mp;
	vector<vector<int>> dp;

	int solve(vector<int>& arr, int i, int j) {
		if (j >= arr.size()) {
			return 0;
		}
		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		int take = 0;
		int next = arr[i] + arr[j];

		if (mp.find(next) != mp.end()) {
			take = 1 + solve(arr, j, mp[next]);
		}

		return dp[i][j] = take;
	}

	int lenLongestFibSubseq(vector<int>& arr) {
		int n = arr.size(), ans = 0;
		dp.resize(n, vector<int>(n, -1));

		for (int i = 0; i < n; i++) {
			mp[arr[i]] = i;
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, solve(arr, i, j));
			}
		}

		return ans == 0 ? 0 : ans + 2;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)