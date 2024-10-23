/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
	TreeNode *replaceValueInTree(TreeNode *root) {
		queue<TreeNode *> q;
		vector<int> levelSum;
		q.push(root);

		while (!q.empty()) {
			int size = q.size();
			long long sum = 0;

			while (size--) {
				TreeNode *node = q.front();
				q.pop();
				sum += node->val;

				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			levelSum.push_back(sum);
		}

		q.push(root);

		root->val = 0;
		int level = 0;

		while (!q.empty()) {
			int size = q.size();
			int sum = level + 1 < levelSum.size() ? levelSum[level + 1] : 0;

			while (size--) {
				int currSum = 0;
				TreeNode *node = q.front();
				q.pop();

				if (node->left) {
					currSum += node->left->val;
					q.push(node->left);
				}
				if (node->right) {
					currSum += node->right->val;
					q.push(node->right);
				}
				if (node->left) {
					node->left->val = sum - currSum;
				}
				if (node->right) {
					node->right->val = sum - currSum;
				}
			}
			level++;
		}
		return root;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)