class Solution {
   public:
	vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
		int n = grid.size();
		int j = 1;

		while (j < n) {
			int x = 0, y = j;
			vector<int> num;
			vector<pair<int, int>> index;

			while (y < n) {
				num.push_back(grid[x][y]);
				index.push_back({x, y});
				x++;
				y++;
			}

			sort(num.begin(), num.end());

			for (int i = 0; i < index.size(); i++) {
				grid[index[i].first][index[i].second] = num[i];
			}
			j++;
		}

		int i = 0;
		while (i < n) {
			int x = i, y = 0;
			vector<int> num;
			vector<pair<int, int>> index;

			while (x < n) {
				num.push_back(grid[x][y]);
				index.push_back({x, y});
				x++;
				y++;
			}

			sort(num.begin(), num.end(), greater<int>());

			for (int i = 0; i < index.size(); i++) {
				grid[index[i].first][index[i].second] = num[i];
			}
			i++;
		}

		return grid;
	}
};

// Time Complexity : O(n ^ 2 * log(n))
// Space Complexity : O(n)