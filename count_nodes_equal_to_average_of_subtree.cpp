class Solution {
public:
    int ans = 0;
    pair<int, int> solve(TreeNode* curr) {
        if (!curr) return {0, 0};

        pair<int, int> left = solve(curr->left);
        pair<int, int> right = solve(curr->right);

        int sum = left.first + right.first + curr->val;
        int count = left.second + right.second + 1;

        if (count != 0 && sum / count == curr->val) ans++; 

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans; 
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)