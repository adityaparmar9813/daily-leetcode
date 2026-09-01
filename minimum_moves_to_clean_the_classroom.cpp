class Solution {
   public:
	int minMoves(vector<string>& classroom, int energy) {
		int m = classroom.size();
		int n = classroom[0].size();
		int start_r = -1, start_c = -1;
		vector<pair<int, int>> litters;
		vector<vector<int>> litter_id(m, vector<int>(n, -1));

		for (int r = 0; r < m; ++r) {
			for (int c = 0; c < n; ++c) {
				if (classroom[r][c] == 'S') {
					start_r = r;
					start_c = c;
				} else if (classroom[r][c] == 'L') {
					litter_id[r][c] = litters.size();
					litters.push_back({r, c});
				}
			}
		}

		int num_litters = litters.size();
		if (num_litters == 0) return 0;
		int target_mask = (1 << num_litters) - 1;

		vector<vector<vector<int8_t>>> max_energy(
		    m, vector<vector<int8_t>>(n, vector<int8_t>(1 << num_litters, -1)));

		struct State {
			int r, c, mask, energy;
		};
		queue<State> q;
		q.push({start_r, start_c, 0, energy});
		max_energy[start_r][start_c][0] = energy;

		int moves = 0;
		int dr[] = {-1, 1, 0, 0};
		int dc[] = {0, 0, -1, 1};

		while (!q.empty()) {
			int sz = q.size();
			while (sz--) {
				State cur = q.front();
				q.pop();

				if (cur.mask == target_mask) return moves;
				if (cur.energy == 0) continue;

				for (int d = 0; d < 4; ++d) {
					int nr = cur.r + dr[d], nc = cur.c + dc[d];
					if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
					if (classroom[nr][nc] == 'X') continue;

					int next_mask = cur.mask;
					if (classroom[nr][nc] == 'L')
						next_mask |= (1 << litter_id[nr][nc]);

					int next_energy = cur.energy - 1;
					if (classroom[nr][nc] == 'R') next_energy = energy;

					if (next_energy > max_energy[nr][nc][next_mask]) {
						max_energy[nr][nc][next_mask] = next_energy;
						q.push({nr, nc, next_mask, next_energy});
					}
				}
			}
			moves++;
		}

		return -1;
	}
};

// Time Complexity: O(n ^ 2 * 2 ^ n)
// Space Complexity: O(n ^ 2 * 2 ^ n)