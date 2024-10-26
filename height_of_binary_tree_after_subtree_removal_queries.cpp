const int N = 100001;

class Solution {
  public:
	int val2H[N], removal[N];

	int solve(TreeNode *root) {
		if (!root) {
			return -1;
		}
		int x = root->val;
		if (val2H[x] != -1) {
			return val2H[x];
		}
		return val2H[x] = 1 + max(solve(root->left), solve(root->right));
	}

	void dfs(TreeNode *root, int level, int maxLevel) {
		if (!root) {
			return;
		}
		int x = root->val;
		removal[x] = maxLevel;

		dfs(root->left, level + 1,
			max(maxLevel, 1 + level + solve(root->right)));
		dfs(root->right, level + 1,
			max(maxLevel, 1 + level + solve(root->left)));
	}

	vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
		memset(val2H, -1, sizeof(val2H));
		memset(removal, -1, sizeof(removal));

		dfs(root, 0, 0);

		vector<int> ans(queries.size());
		int i = 0;
		for (int q : queries) {
			ans[i++] = removal[q];
		}
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)