class Solution {
public:
    void solve(TreeNode*& root, unordered_map<int, bool>& mp, vector<TreeNode*>& ans) {
        if (root == nullptr) {
            return;
        }

        solve(root -> left, mp, ans);
        solve(root -> right, mp, ans);

        if (mp.find(root -> val) != mp.end()) {
            if (root -> left) {
                ans.push_back(root -> left);
            } if (root -> right) {
                ans.push_back(root -> right);
            }
            root = nullptr;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, bool> mp;

        for(int val: to_delete) {
            mp[val] = true;
        }

        vector<TreeNode*> ans;
        solve(root, mp, ans);

        if (root != nullptr) {
            ans.push_back(root);
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
