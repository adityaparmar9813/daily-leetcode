class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) {
            return nullptr;
        }

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }
        return root;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
