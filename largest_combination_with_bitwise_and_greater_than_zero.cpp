class Solution {
  public:
	int largestCombination(vector<int> &candidates) {
		vector<int> dp(24, 0);

		for (int i = 0; i < candidates.size(); i++) {
			for (int j = 0; j < 24; j++) {
				if (candidates[i] & (1 << j)) {
					dp[j]++;
				}
			}
		}

		return *max_element(dp.begin(), dp.end());
	}
};

// Time Complexity : O(N * 24)
// Space Complexity : O(24)