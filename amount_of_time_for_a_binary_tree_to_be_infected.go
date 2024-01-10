func amountOfTime(root *TreeNode, start int) int {
    parentPointers := map[int]*TreeNode{
        root.Val: nil,
    }

    var startNode *TreeNode
    q := []*TreeNode{root}

    for len(q) != 0 {
        cur := q[0]
        q = q[1:]

        if cur.Val == start {
            startNode = cur
        }
        if cur.Left != nil {
            q = append(q, cur.Left)
            parentPointers[cur.Left.Val] = cur
        }
        if cur.Right != nil {
            q = append(q, cur.Right)
            parentPointers[cur.Right.Val] = cur
        }
    }


    res := 0

    q = []*TreeNode{startNode}

    visited := map[int]bool{
        startNode.Val: true,
    }

    for len(q) != 0 {
        n := len(q)
        for i := 0; i < n; i++ {
            cur := q[0]
            q = q[1:]

            neis := []*TreeNode{
                parentPointers[cur.Val],
                cur.Left, cur.Right,
            }

            for _, nei := range neis {
                if nei != nil && !visited[nei.Val] {
                    q = append(q, nei)
                    visited[nei.Val] = true
                }
            }
        }
        res += 1
    }
    return res - 1
}

// Time Complexity : O(n)
// Space Complexity : O(n)
