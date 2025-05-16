class Solution {
   public:
	int solve(int index, int prevIndex, vector<string>& words,
	          vector<int>& groups, vector<vector<int>>& dp,
	          vector<vector<int>>& path) {
		if (index == words.size()) {
			return 0;
		}

		if (dp[index][prevIndex + 1] != -1) {
			return dp[index][prevIndex + 1];
		}

		int ans = solve(index + 1, prevIndex, words, groups, dp, path);
		path[index][prevIndex + 1] = -1;

		if (prevIndex == -1) {
			int include = 1 + solve(index + 1, index, words, groups, dp, path);
			if (include > ans) {
				ans = include;
				path[index][prevIndex + 1] = index;
			}
		} else {
			if (words[prevIndex].size() == words[index].size() &&
			    groups[prevIndex] != groups[index]) {
				bool mismatch = false;
				for (int i = 0; i < words[prevIndex].size(); i++) {
					if (words[prevIndex][i] != words[index][i]) {
						if (mismatch) {
							mismatch = false;
							break;
						} else {
							mismatch = true;
						}
					}
				}

				if (mismatch) {
					int include =
					    1 + solve(index + 1, index, words, groups, dp, path);
					if (include > ans) {
						ans = include;
						path[index][prevIndex + 1] = index;
					}
				}
			}
		}

		return dp[index][prevIndex + 1] = ans;
	}

	vector<string> getWordsInLongestSubsequence(vector<string>& words,
	                                            vector<int>& groups) {
		int n = words.size();
		vector<vector<int>> dp(n, vector<int>(n + 1, -1));
		vector<vector<int>> path(n, vector<int>(n + 1, -1));

		solve(0, -1, words, groups, dp, path);

		vector<string> result;
		int index = 0, prevIndex = -1;

		while (index < n) {
			int chosen = path[index][prevIndex + 1];
			if (chosen == -1) {
				index++;
			} else {
				result.push_back(words[chosen]);
				prevIndex = chosen;
				index = chosen + 1;
			}
		}

		return result;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)