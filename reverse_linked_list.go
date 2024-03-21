func reverseList(head *ListNode) *ListNode {
    var prev, next *ListNode

    for head != nil {
        next = head.Next
        head.Next = prev
        prev = head
        head = next
    }
    return prev
}

// Time Complexity : O(n)
// Space Complexity : O(1)