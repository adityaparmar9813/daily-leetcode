func isSameTree(p *TreeNode, q *TreeNode) bool {
    if(p == nil && q == nil) {
        return true
    } 
    if(p == nil || q == nil) {
        return false
    } 
    if(p.Val != q.Val) {
        return false
    }

    left, right := isSameTree(p.Left, q.Left), isSameTree(p.Right, q.Right)
    return left && right
}

// Time Complexity : O(n)
// Space Complexity : O(n)