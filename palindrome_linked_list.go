func reverseList(head *ListNode) *ListNode {
    var next, prev *ListNode
    
    for head != nil {
        next = head.Next
        head.Next = prev
        prev = head
        head = next
    }
    return prev
}

func isPalindrome(head *ListNode) bool {
    slow, fast := head, head

    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    tail := reverseList(slow)

    for head != nil && tail != nil {
        if head.Val != tail.Val {
            return false
        }
        head = head.Next
        tail = tail.Next
    }
    return true
}

// Time Complexity : O(n)
// Space Complexity : O(1)