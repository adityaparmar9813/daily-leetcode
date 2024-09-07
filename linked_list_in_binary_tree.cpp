class Solution {
  public:
	bool check(ListNode *head, TreeNode *root) {
		if (head == nullptr) {
			return true;
		}
		if (root == nullptr) {
			return false;
		}
		if (head->val != root->val) {
			return false;
		}

		bool left = check(head->next, root->left);
		bool right = check(head->next, root->right);
		return max(left, right);
	}

	bool isSubPath(ListNode *head, TreeNode *root) {
		if (root == nullptr) {
			return false;
		}

		bool curr = check(head, root);
		bool left = isSubPath(head, root->left);
		bool right = isSubPath(head, root->right);

		return max({curr, left, right});
	}
};

// Time Complexity :O(n * m)
// Space Complexity : O(n)