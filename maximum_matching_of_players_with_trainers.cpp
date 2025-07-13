class Solution {
   public:
	int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
		sort(players.begin(), players.end());
		sort(trainers.begin(), trainers.end());

		int currIndex = 0, ans = 0;

		for (int i = 0; i < players.size(); i++) {
			while (currIndex < trainers.size() &&
			       players[i] > trainers[currIndex]) {
				currIndex++;
			}

			if (currIndex < trainers.size()) {
				ans++;
				currIndex++;
			}
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n) + m * log(m))
// Space Complexity : O(1)