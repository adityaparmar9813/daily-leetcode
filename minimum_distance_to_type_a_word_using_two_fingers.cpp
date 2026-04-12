class Solution {
   public:
	vector<vector<vector<int>>> dp;

	int solve(int idx, int f1, int f2, string& word) {
		if (idx == word.size()) return 0;

		if (dp[idx][f1][f2] != -1) {
			return dp[idx][f1][f2];
		}

		int curr = word[idx] - 'A';

		int cost1 = distance(f1, curr) + solve(idx + 1, curr, f2, word);
		int cost2 = distance(f2, curr) + solve(idx + 1, f1, curr, word);

		return dp[idx][f1][f2] = min(cost1, cost2);
	}

	int distance(int from, int to) {
		if (from == 26) {
			return 0;
		}

		int x1 = from / 6, y1 = from % 6;
		int x2 = to / 6, y2 = to % 6;

		return abs(x1 - x2) + abs(y1 - y2);
	}

	int minimumDistance(string word) {
		int n = word.size();
		dp.assign(n, vector<vector<int>>(27, vector<int>(27, -1)));

		return solve(0, 26, 26, word);
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)