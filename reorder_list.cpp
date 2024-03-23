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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* back = reverseList(slow);
        ListNode* front = head;

        while(front->next && back->next) {
            ListNode *temp1 = front, *temp2 = back;

            front = front->next;
            back = back->next;
            temp1->next = temp2;
            temp2->next = front;
        }
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)