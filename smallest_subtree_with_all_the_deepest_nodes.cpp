class Solution {
   public:
	TreeNode* res;
	int bestDepth = 0;

	int dfs(TreeNode* curr, int depth, int maxDepth, int maxDepthCount) {
		if (!curr) {
			return 0;
		}
		if (depth == maxDepth) {
			if (maxDepthCount == 1) {
				res = curr;
				bestDepth = depth;
			}
			return 1;
		}

		int left = dfs(curr->left, depth + 1, maxDepth, maxDepthCount);
		int right = dfs(curr->right, depth + 1, maxDepth, maxDepthCount);

		if (left + right == maxDepthCount && depth > bestDepth) {
			res = curr;
			bestDepth = depth;
		}

		return left + right;
	}

	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		queue<TreeNode*> bfs;
		bfs.push(root);
		int maxDepth = -1, maxDepthCount = 0;

		while (!bfs.empty()) {
			int size = bfs.size();
			maxDepth++;
			maxDepthCount = size;

			while (size--) {
				TreeNode* curr = bfs.front();
				bfs.pop();

				if (curr->left) {
					bfs.push(curr->left);
				}
				if (curr->right) {
					bfs.push(curr->right);
				}
			}
		}

		res = root;
		dfs(root, 0, maxDepth, maxDepthCount);

		return res;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)