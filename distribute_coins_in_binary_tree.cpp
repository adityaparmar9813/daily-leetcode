class Solution {
public:
    int helper(TreeNode* root, int &ans) {
        if (root == nullptr) {
            return 0;
        }

        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        
        ans += abs(left) + abs(right);
        return root->val + left + right - 1;
    }

    int distributeCoins(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(h)
