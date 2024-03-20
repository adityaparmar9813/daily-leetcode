func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
    ptr1 := list1
    for i := 0; i < a-1; i++ {
        ptr1 = ptr1.Next
    }

    ptr2 := ptr1
    for i := 0; i < b-a+1; i++ {
        ptr2 = ptr2.Next
    }

    ptr1.Next = list2
    for list2.Next != nil {
        list2 = list2.Next
    }
    list2.Next = ptr2.Next

    return list1
}

// Time Complexity : O(n)
// Space Complexity : O(1)