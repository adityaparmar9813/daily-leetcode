class Solution {
   public:
	vector<long long> dp;

	long long solve(vector<vector<int>>& questions, int index) {
		if (index >= questions.size()) {
			return 0;
		}

		if (dp[index] != -1) {
			return dp[index];
		}

		long long take = questions[index][0] +
		                 solve(questions, index + questions[index][1] + 1);
		long long notTake = solve(questions, index + 1);

		return dp[index] = max(take, notTake);
	}

	long long mostPoints(vector<vector<int>>& questions) {
		dp.resize(questions.size(), -1);
		return solve(questions, 0);
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)