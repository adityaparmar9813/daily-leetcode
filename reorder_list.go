func reverseList(head *ListNode) *ListNode {
    var next, prev *ListNode = nil, nil
    
    for head != nil {
        next = head.Next
        head.Next = prev
        prev = head
        head = next
    }
    return prev
}

func reorderList(head *ListNode) {
    slow, fast := head, head

    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    back := reverseList(slow)
    front := head

    for front.Next != nil && back.Next != nil {
        temp1, temp2 := front, back

        front = front.Next
        back = back.Next
        temp1.Next = temp2
        temp2.Next = front
    }
}

// Time Complexity : O(n)
// Space Complexity : O(1)