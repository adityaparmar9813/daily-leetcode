class Solution {
  public:
	vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
		int m = box.size(), n = box[0].size();
		vector<vector<char>> newBox(n, vector<char>(m, '.'));

		for (int i = 0; i < m; i++) {
			int emptyIndex = n - 1;

			for (int j = n - 1; j >= 0; j--) {
				if (box[i][j] == '*') {
					emptyIndex = j - 1;
				} else if (box[i][j] == '#') {
					box[i][emptyIndex] = '#';

					if (emptyIndex != j) {
						box[i][j] = '.';
					}
					emptyIndex--;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				newBox[j][m - 1 - i] = box[i][j];
			}
		}

		return newBox;
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n ^ 2)