class Solution {
   public:
	unordered_map<int, int> mp;
	int maxLevel;

	void solve(TreeNode* root, int level) {
		if (root == nullptr) {
			return;
		}

		if (mp.find(level) == mp.end() || mp[level] < root->val) {
			mp[level] = root->val;
		}

		maxLevel = max(level, maxLevel);

		solve(root->left, level + 1);
		solve(root->right, level + 1);
	}

	vector<int> largestValues(TreeNode* root) {
		maxLevel = -1;
		solve(root, 0);

		vector<int> ans(maxLevel + 1);

		for (const auto& [level, maxVal] : mp) {
			ans[level] = maxVal;
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)