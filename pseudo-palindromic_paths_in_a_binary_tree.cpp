class Solution {
public:
    int solve(TreeNode* root, vector<int> mp) {
        mp[root->val]++;
        
        if(!root->left && !root->right) {
            int oddCount = 0;

            for(auto count: mp) {
                if(count % 2 != 0) oddCount++;
            }
            return oddCount > 1 ? 0 : 1;
        }

        int left = 0, right = 0;
        if(root->left) left = solve(root->left, mp);
        if(root->right) right = solve(root->right, mp);
        mp[root->val]--;

        return left + right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> mp(10, 0);
        return solve(root, mp);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
