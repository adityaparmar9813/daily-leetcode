class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        dfs(root, "", ans);
        return ans;
    }
    
    void dfs(TreeNode* root, string path, string& ans) {
        if(!root) return;
        
        path += char('a' + root->val);
        
        if(!root->left && !root->right) {
            reverse(path.begin(), path.end());
            
            if(ans.empty() || path < ans) {
                ans = path;
            }
            reverse(path.begin(), path.end());
        }
        
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
