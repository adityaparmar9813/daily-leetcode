class Solution {
  public:
	TreeNode *reverseOddLevels(TreeNode *root) {
		queue<TreeNode *> q;
		q.push(root);
		bool oddLevel = false;

		while (!q.empty()) {
			int size = q.size();
			vector<TreeNode *> level;

			while (size--) {
				TreeNode *node = q.front();
				q.pop();
				level.push_back(node);

				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}

			if (oddLevel) {
				for (int i = 0; i < level.size() / 2; i++) {
					swap(level[i]->val, level[level.size() - i - 1]->val);
				}
			}

			oddLevel = !oddLevel;
		}

		return root;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)