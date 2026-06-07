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
	TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
		unordered_map<int, TreeNode*> mp;
		set<int> roots;

		for (const auto& d : descriptions) {
			int parent = d[0], child = d[1], isLeft = d[2];

			if (!mp.count(parent)) {
				mp[parent] = new TreeNode(parent);
			}

			if (!mp.count(child)) {
				mp[child] = new TreeNode(child);
			}

			if (isLeft) {
				mp[parent]->left = mp[child];
			} else {
				mp[parent]->right = mp[child];
			}

			roots.insert(parent);
		}

		for (const auto& d : descriptions) {
			roots.erase(d[1]);
		}

		return mp[*roots.begin()];
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)