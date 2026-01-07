class Solution {
   public:
	int mini = 1e9;
	const int MOD = 1e9 + 7;

	int dfs1(TreeNode* curr) {
		if (!curr) {
			return 0;
		}
		return curr->val + dfs1(curr->left) + dfs1(curr->right);
	}

	int dfs2(TreeNode* curr, int total) {
		if (!curr) {
			return 0;
		}

		int sum =
		    curr->val + dfs2(curr->left, total) + dfs2(curr->right, total);
		if (abs(total - 2 * sum) < mini) {
			mini = abs(total - 2 * sum);
		}
		return sum;
	}

	int maxProduct(TreeNode* root) {
		int total = dfs1(root);
		dfs2(root, total);

		int first = (total - mini) / 2;
		int second = total - first;

		long long ans = (1ll * first * second) % MOD;
		return (int)ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)