class Solution {
   public:
	int dfs(TreeNode* curr, int depth, int* maxDepth, TreeNode** ans) {
		if (!curr) {
			return depth - 1;
		}

		int leftDepth = dfs(curr->left, depth + 1, maxDepth, ans);
		int rightDepth = dfs(curr->right, depth + 1, maxDepth, ans);

		int currentDepth = max(leftDepth, rightDepth);
		*maxDepth = max(*maxDepth, currentDepth);

		if (leftDepth == *maxDepth && rightDepth == *maxDepth) {
			*ans = curr;
		}
		return currentDepth;
	}

	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		TreeNode* ans = nullptr;
		int maxDepth = 0;
		dfs(root, 0, &maxDepth, &ans);
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(h)