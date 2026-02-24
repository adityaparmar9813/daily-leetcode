class Solution {
   public:
	int solve(TreeNode* root, int curr) {
		if (!root) {
			return 0;
		}

		if (!root->left && !root->right) {
			return (curr << 1) | root->val;
		}

		int newCurr = (curr << 1) | root->val;
		return solve(root->left, newCurr) + solve(root->right, newCurr);
	}

	int sumRootToLeaf(TreeNode* root) { return solve(root, 0); }
};

// Time Complexity: O(n)
// Space Complexity: O(n)