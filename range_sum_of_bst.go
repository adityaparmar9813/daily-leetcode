func rangeSumBST(root *TreeNode, low int, high int) int {
    if root == nil {
        return 0
    }
    val := 0
    if root.Val >= low && root.Val <= high {
        val = root.Val
    }

    return val + rangeSumBST(root.Left, low, high) + rangeSumBST(root.Right, low, high)
}

// Time Complexity : O(n)
// Space Complexity : O(n)
