class Solution {
   public:
	int getIndex(vector<int>& days, int curr, int limit) {
		int index = curr;

		while (index < days.size() && days[index] <= days[curr] + limit - 1) {
			index++;
		}
		return index;
	}

	int solve(vector<int>& days, vector<int>& costs, int index,
	          vector<int>& dp) {
		if (index == days.size()) {
			return 0;
		}

		if (dp[index] != -1) {
			return dp[index];
		}

		int dayPass =
		    costs[0] + solve(days, costs, getIndex(days, index, 1), dp);
		int weekPass =
		    costs[1] + solve(days, costs, getIndex(days, index, 7), dp);
		int monthPass =
		    costs[2] + solve(days, costs, getIndex(days, index, 30), dp);

		return dp[index] = min({dayPass, weekPass, monthPass});
	}

	int mincostTickets(vector<int>& days, vector<int>& costs) {
		sort(days.begin(), days.end());
		vector<int> dp(days.size(), -1);
		return solve(days, costs, 0, dp);
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)