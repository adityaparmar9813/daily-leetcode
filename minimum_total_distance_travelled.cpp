class Solution {
  public:
	long long solve(vector<int> &robot, vector<vector<int>> &factory, int i,
					int j, vector<vector<vector<long long>>> &dp) {
		if (i >= robot.size()) {
			return 0;
		}
		if (j >= factory.size()) {
			return LONG_MAX;
		}
		if (dp[i][j][factory[j][1]] != -1) {
			return dp[i][j][factory[j][1]];
		}

		long long take = 1e15;
		long long notTake = solve(robot, factory, i, j + 1, dp);

		if (factory[j][1] > 0) {
			int distance = abs(robot[i] - factory[j][0]);
			factory[j][1]--;
			take = distance + solve(robot, factory, i + 1, j, dp);
			factory[j][1]++;
		}

		return dp[i][j][factory[j][1]] = min(take, notTake);
	}

	long long minimumTotalDistance(vector<int> &robot,
								   vector<vector<int>> &factory) {
		sort(robot.begin(), robot.end());
		sort(factory.begin(), factory.end());

		vector<vector<vector<long long>>> dp(
			robot.size(), vector<vector<long long>>(
							  factory.size(), vector<long long>(101, -1)));
		return solve(robot, factory, 0, 0, dp);
	}
};

// Time Complexity: O(N * M * 100)
// Space Complexity: O(N * M * 100)