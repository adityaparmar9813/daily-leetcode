class Solution {
   public:
	int maxLevelSum(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		int level = 1, ans = 0;
		long long maxSum = -1e9;

		while (!q.empty()) {
			int size = q.size();
			long long currSum = 0;

			while (size--) {
				TreeNode* curr = q.front();
				currSum += curr->val;

				if (curr->left) {
					q.push(curr->left);
				}
				if (curr->right) {
					q.push(curr->right);
				}
				q.pop();
			}

			if (currSum > maxSum) {
				maxSum = currSum;
				ans = level;
			}
			level++;
		}

		return ans;
	}
}

// Time Complexity: O(n)
// Space Complexity: O(n)