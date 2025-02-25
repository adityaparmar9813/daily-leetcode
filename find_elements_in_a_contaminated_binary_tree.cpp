class FindElements {
   public:
	set<int> st;

	void solve(TreeNode* root, int curr) {
		if (!root) {
			return;
		}

		st.insert(curr);

		solve(root->left, 2 * curr + 1);
		solve(root->right, 2 * curr + 2);
	}

	FindElements(TreeNode* root) { solve(root, 0); }

	bool find(int target) { return st.find(target) != st.end(); }
};

// Time Complexity: O(n)
// Space Complexity: O(n)