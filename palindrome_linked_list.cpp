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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tail = reverseList(slow);

        while(head && tail) {
            if(head->val != tail->val) {
                return false;
            }
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)