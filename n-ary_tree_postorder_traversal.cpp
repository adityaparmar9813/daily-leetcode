class Solution {
  public:
	vector<int> post;
	vector<int> postorder(Node *root) {
		if (!root) {
			return {};
		}

		for (Node *child : root->children) {
			postorder(child);
		}

		post.push_back(root->val);
		return post;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)