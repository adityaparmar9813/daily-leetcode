class Solution {
   public:
	int count = 0;

	void dfs(string &tiles, vector<bool> &visited, string curr) {
		for (int i = 0; i < tiles.size(); i++) {
			if (visited[i] ||
			    (i > 0 && tiles[i] == tiles[i - 1] && !visited[i - 1])) {
				continue;
			}

			visited[i] = true;
			count++;
			dfs(tiles, visited, curr + tiles[i]);
			visited[i] = false;
		}
	}

	int numTilePossibilities(string tiles) {
		sort(tiles.begin(), tiles.end());
		vector<bool> visited(tiles.size(), false);
		dfs(tiles, visited, "");
		return count;
	}
};

// Time Complexity: O(n!)
// Space Complexity: O(n)