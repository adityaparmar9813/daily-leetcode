class Solution {
public:
    int dfs(TreeNode* root, int curr) {
        if(!root) {
            return 0;
        }
        if(!root->left && !root->right) {
            return curr*10 + root->val;
        }

        int left = dfs(root->left, curr*10 + root->val);
        int right = dfs(root->right, curr*10 + root->val);

        root->left = root->right = nullptr;

        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
