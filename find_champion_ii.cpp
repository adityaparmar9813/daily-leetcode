class Solution {
  public:
	int findChampion(int n, vector<vector<int>> &edges) {
		vector<bool> incoming(n, false);

		for (const auto &edge : edges) {
			incoming[edge[1]] = true;
		}

		int winner = -1;

		for (int i = 0; i < n; i++) {
			if (incoming[i] == false) {
				if (winner != -1) {
					return -1;
				}
				winner = i;
			}
		}

		return winner;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)