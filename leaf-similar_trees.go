func formSequence(root *TreeNode, seq *[]int) {
    if root == nil {
        return
    }
    if root.Left == nil && root.Right == nil {
        *seq = append(*seq, root.Val)
    }

    formSequence(root.Left, seq)
    formSequence(root.Right, seq)
}

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
    seq1, seq2 := make([]int, 0), make([]int, 0)
    formSequence(root1, &seq1)
    formSequence(root2, &seq2)

    if len(seq1) != len(seq2) {
        return false
    }
    for i := 0; i < len(seq1); i++ {
        if seq1[i] != seq2[i] {
            return false
        }
    }
    return true
}

// Time Complexity : O(n)
// Space Complexity : O(n)
