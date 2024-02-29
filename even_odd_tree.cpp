class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool evenLevel = true;

        while(!q.empty()) {
            int size = q.size();
            int prev = evenLevel ? 0 : INT_MAX;

            while(size--) {
                TreeNode* curr = q.front();
                q.pop();

                if(evenLevel) {
                    if(curr -> val % 2 == 0) return false;
                    if(prev >= curr -> val) return false;
                } else {
                    if(curr -> val % 2 != 0) return false;
                    if(prev <= curr -> val) return false;
                }
                prev = curr -> val;

                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
            evenLevel = !evenLevel;
        }
        return true;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)