class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->val == 0) {
            return false;
        } if (root->val == 1) {
            return true;
        } if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        } else {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
