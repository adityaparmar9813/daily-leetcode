class Solution {
   public:
	bool check(int curr, vector<vector<int>>& adjacencyList,
	           vector<int>& visited) {
		if (visited[curr] == 1) {
			return true;
		}
		if (visited[curr] == 0) {
			return false;
		}

		visited[curr] = 0;

		for (int node : adjacencyList[curr]) {
			if (!check(node, adjacencyList, visited)) {
				return false;
			}
		}

		visited[curr] = 1;
		return true;
	}

	void search(int curr, vector<vector<int>>& adjacencyList,
	            vector<vector<int>>& connected, vector<int>& visited,
	            string& colors) {
		if (visited[curr]) {
			return;
		}
		visited[curr] = 1;

		for (int neighbor : adjacencyList[curr]) {
			search(neighbor, adjacencyList, connected, visited, colors);

			for (int i = 0; i < 26; i++) {
				connected[curr][i] =
				    max(connected[curr][i], connected[neighbor][i]);
			}
		}

		connected[curr][colors[curr] - 'a']++;
	}

	int largestPathValue(string colors, vector<vector<int>>& edges) {
		vector<vector<int>> adjacencyList(colors.size());
		vector<vector<int>> connected(colors.size(), vector<int>(26, 0));
		vector<int> visited(colors.size(), -1);

		for (const auto& edge : edges) {
			adjacencyList[edge[0]].push_back(edge[1]);
		}

		for (int i = 0; i < colors.size(); i++) {
			if (!check(i, adjacencyList, visited)) {
				return -1;
			}
		}

		fill(visited.begin(), visited.end(), 0);
		int result = 0;

		for (int i = 0; i < colors.size(); i++) {
			search(i, adjacencyList, connected, visited, colors);
			result = max(
			    result, *max_element(connected[i].begin(), connected[i].end()));
		}

		return result;
	}
};

// Time Complexity : O(n + m)
// Space Complexity : O(n + m)