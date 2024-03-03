class Solution {
public:
    int solve(ListNode* head, int n) {
        if(!head) return 0;
        int index = solve(head->next, n);
        
        if(index == n) head->next = head->next->next;
        return 1 + index;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode;
        dummyHead->next = head;
        solve(dummyHead, n);
        return dummyHead->next;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)