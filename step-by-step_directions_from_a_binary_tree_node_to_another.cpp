/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode *root, int startValue, int destValue) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == startValue || root->val == destValue) {
            return root;
        }

        TreeNode* l = lca(root->left, startValue, destValue);
        TreeNode* r = lca(root->right, startValue, destValue);

        if (l != nullptr && r != nullptr) {
            return root;
        }
        return l != nullptr ? l : r;
    }
    bool getPath(TreeNode *root, int value, string &path) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == value) {
            return true;
        }

        path += 'L';
        bool res = getPath(root->left, value, path);

        if (res == true) {
            return true;
        }
        path.pop_back();

        path += 'R';
        res = getPath(root->right, value, path);
        
        if (res == true) {
            return true;
        }
        path.pop_back();
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startValuePath, endValuePath;
        root = lca(root, startValue, destValue);

        getPath(root, startValue, startValuePath);
        getPath(root, destValue, endValuePath);

        for (char &ch: startValuePath) {
            ch = 'U';
        }
        return startValuePath + endValuePath;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
