class Solution {
public:
    unordered_map<int, int> mp;

    void solve(TreeNode* root) {
        if(!root) return;
        mp[root->val]++;

        solve(root->left);
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        vector<int> ans;
        int maxi = INT_MIN;

        for(auto el: mp) {
            if(el.second == maxi) ans.push_back(el.first);
            else if(el.second > maxi) {
                ans.clear();
                ans.push_back(el.first);
                maxi = el.second;
            }
        }
        return ans;
    }
};