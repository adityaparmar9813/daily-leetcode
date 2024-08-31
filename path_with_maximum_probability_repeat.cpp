class Solution {
  public:
	double maxProbability(int n, vector<vector<int>> &edges,
						  vector<double> &succProb, int start_node,
						  int end_node) {
		vector<vector<pair<int, double>>> adjacencyList(n);

		for (int i = 0; i < edges.size(); i++) {
			adjacencyList[edges[i][0]].push_back({edges[i][1], succProb[i]});
			adjacencyList[edges[i][1]].push_back({edges[i][0], succProb[i]});
		}

		priority_queue<pair<double, int>> q;
		q.push({1.0, start_node});

		vector<double> visited(n, 0.0);
		visited[start_node] = 1.0;

		while (!q.empty()) {
			double currProb = q.top().first;
			int node = q.top().second;
			q.pop();

			if (node == end_node) {
				return currProb;
			}

			for (auto &neighbor : adjacencyList[node]) {
				int nextNode = neighbor.first;
				double edgeProb = neighbor.second;

				double newProb = currProb * edgeProb;

				if (newProb > visited[nextNode]) {
					visited[nextNode] = newProb;
					q.push({newProb, nextNode});
				}
			}
		}
		return 0.0;
	}
};

// Time Complexity : O(e * log(v))
// Space Complexity : O(e + v)