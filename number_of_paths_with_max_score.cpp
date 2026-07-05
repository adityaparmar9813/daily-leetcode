class Solution {
   public:
	vector<int> pathsWithMaxScore(vector<string>& board) {
		const int MOD = 1000000007;
		int n = board.size();

		vector<int> nextScore(n + 1, -1);
		vector<int> nextWays(n + 1, 0);

		for (int i = n - 1; i >= 0; --i) {
			vector<int> currScore(n + 1, -1);
			vector<int> currWays(n + 1, 0);

			for (int j = n - 1; j >= 0; --j) {
				char cell = board[i][j];

				if (cell == 'X') {
					continue;
				}

				if (cell == 'S') {
					currScore[j] = 0;
					currWays[j] = 1;
					continue;
				}

				int best =
				    max({nextScore[j], currScore[j + 1], nextScore[j + 1]});

				if (best == -1) {
					continue;
				}

				long long ways = 0;

				if (nextScore[j] == best) {
					ways += nextWays[j];
				}
				if (currScore[j + 1] == best) {
					ways += currWays[j + 1];
				}
				if (nextScore[j + 1] == best) {
					ways += nextWays[j + 1];
				}

				int value = (cell == 'E') ? 0 : cell - '0';

				currScore[j] = best + value;
				currWays[j] = ways % MOD;
			}

			nextScore = move(currScore);
			nextWays = move(currWays);
		}

		if (nextScore[0] == -1) {
			return {0, 0};
		}

		return {nextScore[0], nextWays[0]};
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)