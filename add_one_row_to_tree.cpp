class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        TreeNode* dummy = new TreeNode();

        dummy->left = root;
        q.push(dummy);

        int curr_depth = 0;

        while(!q.empty()) {
            int size = q.size();
            bool flag = false;

            while(size--) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr_depth == depth-1) {
                    TreeNode* node1 = new TreeNode(val);
                    TreeNode* node2 = new TreeNode(val);

                    node1->left = curr->left;
                    node2->right = curr->right;

                    curr->left = node1;
                    curr->right = node2;
                    flag = true;
                }

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            curr_depth++;
            
            if(flag) {
                break;
            }
        }
        return dummy->left;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
