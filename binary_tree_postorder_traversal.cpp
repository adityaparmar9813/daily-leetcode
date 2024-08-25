class Solution {
  public:
	vector<int> postorder;
	vector<int> postorderTraversal(TreeNode *root) {
		if (!root) {
			return {};
		}
		if (root->left) {
			postorderTraversal(root->left);
		}
		if (root->right) {
			postorderTraversal(root->right);
		}
		postorder.push_back(root->val);
		return postorder;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)