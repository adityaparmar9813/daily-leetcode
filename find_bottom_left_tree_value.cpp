class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* ans;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            ans = q.front();

            while(size--) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
        }
        return ans -> val;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)