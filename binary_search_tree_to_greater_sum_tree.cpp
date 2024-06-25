class Solution {
public:
    int sum = 0;

    TreeNode* bstToGst(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        bstToGst(root -> right);
        sum += root -> val;
        root -> val = sum;
        bstToGst(root -> left);

        return root;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
