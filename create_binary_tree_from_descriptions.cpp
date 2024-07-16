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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> s;

        for (auto description: descriptions) {
            int p = description[0];
            int c = description[1];
            int left = description[2];

            if (mp.find(p) == mp.end()) {
                mp[p] = new TreeNode(p);
            }

            if (mp.find(c) == mp.end()) {
                mp[c] = new TreeNode(c);
            }

            if (left == 1) {
                mp[p]->left = mp[c];
            } else {
                mp[p]->right = mp[c];
            }
            s.insert(c);
        }

        for(auto description: descriptions){
            int p = description[0];

            if (s.find(p) == s.end()) {
                return mp[p];
            }
        }
        return nullptr;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
