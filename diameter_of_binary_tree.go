func dfs(root *TreeNode, ans *int) int {
    if(root == nil) {
        return 0
    }

    left := dfs(root.Left, ans)
    right := dfs(root.Right, ans)

    *ans = max(*ans, left+right)
    return 1 + max(left, right)
}
func diameterOfBinaryTree(root *TreeNode) int {
    ans := 0
    dfs(root, &ans);
    return ans
}

// Time Complexity : O(n)
// Space Complexity : O(n)