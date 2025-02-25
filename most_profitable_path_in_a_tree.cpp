class Solution {
   public:
	int mostProfitablePath(vector<vector<int>>& edges, int bob,
	                       vector<int>& amount) {
		int n = amount.size();
		tree.resize(n);
		visited.assign(n, false);

		for (vector<int> edge : edges) {
			tree[edge[0]].push_back(edge[1]);
			tree[edge[1]].push_back(edge[0]);
		}

		findBobPath(bob, 0);

		visited.assign(n, false);
		findAlicePath(0, 0, 0, amount);

		return maxIncome;
	}

   private:
	unordered_map<int, int> bobPath;
	vector<bool> visited;
	vector<vector<int>> tree;
	int maxIncome = INT_MIN;

	bool findBobPath(int sourceNode, int time) {
		bobPath[sourceNode] = time;
		visited[sourceNode] = true;

		if (sourceNode == 0) {
			return true;
		}

		for (int adjacentNode : tree[sourceNode]) {
			if (!visited[adjacentNode] && findBobPath(adjacentNode, time + 1)) {
				return true;
			}
		}

		bobPath.erase(sourceNode);
		return false;
	}

	void findAlicePath(int sourceNode, int time, int income,
	                   vector<int>& amount) {
		visited[sourceNode] = true;

		if (bobPath.find(sourceNode) == bobPath.end() ||
		    time < bobPath[sourceNode]) {
			income += amount[sourceNode];
		}

		else if (time == bobPath[sourceNode]) {
			income += (amount[sourceNode] / 2);
		}

		if (tree[sourceNode].size() == 1 && sourceNode != 0) {
			maxIncome = max(maxIncome, income);
		}

		for (int adjacentNode : tree[sourceNode]) {
			if (!visited[adjacentNode]) {
				findAlicePath(adjacentNode, time + 1, income, amount);
			}
		}
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)