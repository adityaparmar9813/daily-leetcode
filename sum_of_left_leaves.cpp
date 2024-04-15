class Solution {
public:
    int dfs(TreeNode* root, bool isLeft) {
        if(!root) {
            return 0;
        }
        if(!root->left && !root->right) {
            return isLeft ? root->val : 0;
        }

        int left = dfs(root->left, true);
        int right = dfs(root->right, false);
        root->left = root->right = nullptr;

        return left + right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
