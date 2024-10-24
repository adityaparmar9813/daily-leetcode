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
	void solve(TreeNode *root, int level, vector<vector<int>> &mp) {
		mp[root->val][0] = level;

		if (root->left) {
			mp[root->val][1] = root->left->val;
			solve(root->left, level + 1, mp);
		}
		if (root->right) {
			mp[root->val][2] = root->right->val;
			solve(root->right, level + 1, mp);
		}
	}

	bool flipEquiv(TreeNode *root1, TreeNode *root2) {
		vector<vector<int>> mp1(100, vector<int>(3, -1));
		vector<vector<int>> mp2(100, vector<int>(3, -1));

		if (root1 != nullptr) {
			solve(root1, 0, mp1);
		}
		if (root2 != nullptr) {
			solve(root2, 0, mp2);
		}

		for (int i = 0; i < 100; i++) {
			vector<int> children1 = {min(mp1[i][1], mp1[i][2]),
									 max(mp1[i][1], mp1[i][2])};
			vector<int> children2 = {min(mp2[i][1], mp2[i][2]),
									 max(mp2[i][1], mp2[i][2])};

			if (mp1[i][0] != mp2[i][0] || children1 != children2) {
				return false;
			}
		}
		return true;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)