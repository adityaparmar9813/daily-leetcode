class Solution {
  public:
	bool checkSuccess(vector<vector<int>> &board) {
		return board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 &&
			   board[1][0] == 4 && board[1][1] == 5;
	}

	string serializeBoard(vector<vector<int>> &board) {
		string s = "";
		for (auto &row : board) {
			for (auto &cell : row) {
				s += to_string(cell);
			}
		}
		return s;
	}

	int slidingPuzzle(vector<vector<int>> &board) {
		unordered_set<string> visited;
		queue<vector<vector<int>>> q;
		q.push(board);
		int moves = 0;

		vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

		while (!q.empty()) {
			int size = q.size();

			while (size--) {
				vector<vector<int>> currBoard = q.front();
				q.pop();

				string serialized = serializeBoard(currBoard);

				if (visited.count(serialized)) {
					continue;
				}

				visited.insert(serialized);

				if (checkSuccess(currBoard)) {
					return moves;
				}

				int zi, zj;
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 3; j++) {
						if (currBoard[i][j] == 0) {
							zi = i;
							zj = j;
							break;
						}
					}
				}

				for (auto &dir : directions) {
					int newZi = zi + dir.first;
					int newZj = zj + dir.second;

					if (newZi >= 0 && newZi < 2 && newZj >= 0 && newZj < 3) {
						swap(currBoard[zi][zj], currBoard[newZi][newZj]);
						q.push(currBoard);
						swap(currBoard[zi][zj], currBoard[newZi][newZj]);
					}
				}
			}

			moves++;
		}

		return -1;
	}
};

// Time Complexity : O(1)
// Space Complexity : O(1)