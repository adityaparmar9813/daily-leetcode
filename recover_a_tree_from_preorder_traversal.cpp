class Solution {
   public:
	string path;
	int getDepth() {
		int n = path.length(), idx = 0;
		for (; idx < n && path[idx] == '-'; idx++) {
		}
		return idx;
	}
	int getValue() {
		int n = path.length(), idx = 0, num = 0;
		for (; idx < n; ++idx) {
			if (path[idx] != '-') break;
		}
		for (; idx < n; idx++) {
			if (path[idx] == '-') break;
			int digit = path[idx] - '0';
			num = num * 10 + digit;
		}
		path = path.substr(idx);
		return num;
	}
	TreeNode* dfs(int required_depth) {
		int available_depth = getDepth();
		if (required_depth > available_depth) {
			return NULL;
		}
		int value = getValue();
		TreeNode* root = new TreeNode(value);
		root->left = dfs(required_depth + 1);
		root->right = dfs(required_depth + 1);
		return root;
	}
	TreeNode* recoverFromPreorder(string traversal) {
		path = traversal;
		return dfs(0);
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)