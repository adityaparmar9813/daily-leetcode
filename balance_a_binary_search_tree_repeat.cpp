class Solution {
   public:
	vector<int> inorder;

	void inorderTraversal(TreeNode* root) {
		if (!root) {
			return;
		}

		inorderTraversal(root->left);
		inorder.push_back(root->val);
		inorderTraversal(root->right);
	}

	TreeNode* buildTree(vector<int>& traversal, int l, int r) {
		if (l > r) {
			return nullptr;
		}

		int mid = (l + r) / 2;
		return new TreeNode(traversal[mid], buildTree(traversal, l, mid - 1),
		                    buildTree(traversal, mid + 1, r));
	}

	TreeNode* balanceBST(TreeNode* root) {
		inorderTraversal(root);
		return buildTree(inorder, 0, inorder.size() - 1);
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)