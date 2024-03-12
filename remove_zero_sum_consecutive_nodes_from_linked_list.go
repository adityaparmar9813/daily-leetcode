func removeZeroSumSublists(head *ListNode) *ListNode {
    dummyHead := &ListNode{Val: 0}
    dummyHead.Next = head
    curr := dummyHead

    for curr != nil {
        ptr := curr.Next
        sum := 0

        for ptr != nil {
            sum += ptr.Val
            if sum == 0 {
                curr.Next = ptr.Next
            }
            ptr = ptr.Next
        }
        curr = curr.Next
    }
    return dummyHead.Next
}

// Time Complexity : O(n^2)
// Space Complexity : O(1)