class Solution {
   public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int x = 0, y = 0, dir = 0, ans = 0;
		set<pair<int, int>> st;

		for (const auto& obstacle : obstacles) {
			st.insert({obstacle[0], obstacle[1]});
		}

		vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

		for (int command : commands) {
			if (command == -2) {
				dir = (dir + 3) % 4;
			} else if (command == -1) {
				dir = (dir + 1) % 4;
			} else {
				for (int i = 0; i < command; i++) {
					int nx = x + dirs[dir].first;
					int ny = y + dirs[dir].second;

					if (st.count({nx, ny})) {
						break;
					}

					x = nx;
					y = ny;
					ans = max(ans, x * x + y * y);
				}
			}
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)