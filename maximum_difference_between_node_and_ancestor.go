/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxAncestorDiff(root *TreeNode) (res int) {
	solve(root, 100001, -1, &res)
	return res
}

func solve(node *TreeNode, minimumAncestor int, maximumAncestor int, maxAbsDiff *int) {
	if node == nil {
		return
	}

	maxDiff := max(
		int(math.Abs(float64(minimumAncestor - node.Val))),
		int(math.Abs(float64(maximumAncestor - node.Val))),
	)

	if maximumAncestor == -1 {
		maxDiff = 0
	}

	*maxAbsDiff = max(*maxAbsDiff, maxDiff)

	solve(node.Left, min(minimumAncestor, node.Val), max(maximumAncestor, node.Val), maxAbsDiff)
	solve(node.Right, min(minimumAncestor, node.Val), max(maximumAncestor, node.Val), maxAbsDiff)
}

// Time Complexity : O(n)
// Spcae Complexity : O(n)
