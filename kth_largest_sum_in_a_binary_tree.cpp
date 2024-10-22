class Solution {
  public:
	long long kthLargestLevelSum(TreeNode *root, int k) {
		vector<long long> levelSum;
		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty()) {
			int size = q.size();
			long long sum = 0;

			while (size--) {
				TreeNode *curr = q.front();
				q.pop();
				sum += curr->val;

				if (curr->left) {
					q.push(curr->left);
				}
				if (curr->right) {
					q.push(curr->right);
				}
			}
			levelSum.push_back(sum);
		}

		if (k > levelSum.size()) {
			return -1;
		}

		sort(levelSum.begin(), levelSum.end(), greater<long long>());
		return levelSum[k - 1];
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)