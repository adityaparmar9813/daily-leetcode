class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *next = nullptr, *prev = nullptr;
        
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)