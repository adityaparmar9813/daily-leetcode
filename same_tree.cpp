class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p -> val != q -> val) return false;

        int left = isSameTree(p -> left, q -> left);
        int right = isSameTree(p -> right, q -> right);

        return left && right;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)