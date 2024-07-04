class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev = head -> next;
        ListNode* curr = head -> next;

        ListNode* dummyHead = new ListNode();
        dummyHead -> next = head -> next;

        int sum = 0;
        
        while (curr != nullptr) {
            if (curr -> val != 0) {
                sum += curr -> val;
            } else {
                prev -> val = sum;
                prev -> next = curr -> next;
                prev = prev -> next;
                sum = 0;
            }

            curr = curr -> next;
        } 
        return dummyHead -> next;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
