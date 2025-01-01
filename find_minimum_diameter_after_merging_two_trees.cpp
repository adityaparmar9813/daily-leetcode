#define MAX_NODES 200005

template <typename T>
void updateMax(T& current, T candidate) {
	current = max(current, candidate);
}

template <typename T>
void updateMin(T& current, T candidate) {
	current = min(current, candidate);
}

vector<int> adjacencyList[MAX_NODES];
int depth[MAX_NODES], farthestNodeA, farthestNodeB;

void depthFirstSearch(int currentNode, int parentNode, int& farthestNode) {
	depth[currentNode] = depth[parentNode] + 1;
	if (farthestNode == -1 || depth[currentNode] > depth[farthestNode]) {
		farthestNode = currentNode;
	}
	for (int neighbor : adjacencyList[currentNode]) {
		if (neighbor != parentNode) {
			depthFirstSearch(neighbor, currentNode, farthestNode);
		}
	}
}

int calculateTreeDiameter() {
	farthestNodeA = -1;
	depthFirstSearch(1, 0, farthestNodeA);

	farthestNodeB = -1;
	depthFirstSearch(farthestNodeA, 0, farthestNodeB);

	return depth[farthestNodeB] - 1;
}

class Solution {
   public:
	pair<int, int> processTree(const vector<vector<int>>& edges) {
		int nodeCount = edges.size() + 1;
		for (int i = 1; i <= nodeCount; i++) {
			adjacencyList[i].clear();
		}
		for (const auto& edge : edges) {
			int nodeU = edge[0] + 1;
			int nodeV = edge[1] + 1;
			adjacencyList[nodeU].push_back(nodeV);
			adjacencyList[nodeV].push_back(nodeU);
		}
		int diameter = calculateTreeDiameter();
		return {diameter / 2, diameter - diameter / 2};
	}

	int minimumDiameterAfterMerge(vector<vector<int>>& edgesTree1,
	                              vector<vector<int>>& edgesTree2) {
		pair<int, int> tree1 = processTree(edgesTree1);
		pair<int, int> tree2 = processTree(edgesTree2);

		int minDiameter =
		    max(tree1.first + tree1.second, tree2.first + tree2.second);
		updateMax(minDiameter, max(tree1.first, tree1.second) +
		                           max(tree2.first, tree2.second) + 1);

		return minDiameter;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)