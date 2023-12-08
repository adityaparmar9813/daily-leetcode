class Solution {
public:
    string append(TreeNode* root) {
        string ans;
        ans += '(';
        ans += tree2str(root);
        if(ans.back() == '(') ans.pop_back();
        else ans += ')';
        return ans;
    }

    string tree2str(TreeNode* root) {
        if(!root) return "";
        string ans;
        ans += to_string(root->val);

        if(!root->left && !root->right) return ans;
        if(!root->left && root->right) ans += "()";

        ans += append(root->left);
        ans += append(root->right);
        return ans;
    }
};