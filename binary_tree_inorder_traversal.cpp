class Solution {
public:
    vector<int> inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);

        return inorder;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)