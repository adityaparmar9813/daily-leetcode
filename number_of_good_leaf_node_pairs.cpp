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

    vector<int> solve(TreeNode* root, int distance, int& count){
        if (root == nullptr) {
            return {0};
        }
        if (root -> left == nullptr && root -> right == nullptr) {
            return {1};
        }

        vector<int> left = solve(root -> left, distance, count);
        vector<int> right = solve(root -> right, distance, count);

        for (int i: left) {
            for (int j: right) {
                if (i > 0 && j > 0 && i+j <= distance) {
                    count++;
                }
            }
        }

        vector<int> ans;
        for (int dist: left) {
            if (dist > 0 && dist < distance) {
                ans.push_back(dist+1);
            }
        }

        for (int dist: right) {
            if (dist > 0 && dist < distance) {
                ans.push_back(dist+1);
            }
        }
        return ans;
        
    }

    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        solve(root, distance, count);

        return count;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)
