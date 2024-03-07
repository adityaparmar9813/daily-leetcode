func middleNode(head *ListNode) *ListNode {
    slow, fast := head, head

    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    return slow
}

// Time Complexity : O(n)
// Space Complexity : O(1)