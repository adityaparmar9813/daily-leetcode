class Solution {
  public:
	int minimumOperations(TreeNode *root) {
		queue<TreeNode *> q;
		q.push(root);
		int ans = 0;

		while (!q.empty()) {
			int size = q.size();

			vector<int> idx(size);
			iota(idx.begin(), idx.end(), 0);

			int index = 0;
			vector<int> level(size);

			for (int i = 0; i < size; i++) {
				TreeNode *curr = q.front();
				level[index++] = curr->val;
				q.pop();

				if (curr->left) {
					q.push(curr->left);
				}
				if (curr->right) {
					q.push(curr->right);
				}
			}

			sort(idx.begin(), idx.end(),
				 [&](int i, int j) { return level[i] < level[j]; });

			vector<bool> visited(size, false);
			for (int i = 0; i < size; i++) {
				if (visited[i] || idx[i] == i)
					continue;

				int cycle_size = 0;
				int j = i;

				while (!visited[j]) {
					visited[j] = true;
					j = idx[j];
					cycle_size++;
				}

				if (cycle_size > 1) {
					ans += cycle_size - 1;
				}
			}
		}

		return ans;
	}
};

// Tiime Complexity: O(n ^ 2)
// Space Complexity: O(n)