class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root) {
        if(!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        ans = max(ans, left+right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)