class Solution {
   public:
	TreeNode* constructFromPrePost(vector<int>& preorder,
	                               vector<int>& postorder) {
		int numOfNodes = preorder.size();

		vector<int> indexInPostorder(numOfNodes + 1);
		for (int index = 0; index < numOfNodes; index++) {
			indexInPostorder[postorder[index]] = index;
		}

		return constructTree(0, numOfNodes - 1, 0, preorder, indexInPostorder);
	}

   private:
	TreeNode* constructTree(int preStart, int preEnd, int postStart,
	                        vector<int>& preorder,
	                        vector<int>& indexInPostorder) {
		if (preStart > preEnd) return NULL;

		if (preStart == preEnd) {
			return new TreeNode(preorder[preStart]);
		}

		int leftRoot = preorder[preStart + 1];
		int numOfNodesInLeft = indexInPostorder[leftRoot] - postStart + 1;

		TreeNode* root = new TreeNode(preorder[preStart]);

		root->left = constructTree(preStart + 1, preStart + numOfNodesInLeft,
		                           postStart, preorder, indexInPostorder);

		root->right = constructTree(preStart + numOfNodesInLeft + 1, preEnd,
		                            postStart + numOfNodesInLeft, preorder,
		                            indexInPostorder);

		return root;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)