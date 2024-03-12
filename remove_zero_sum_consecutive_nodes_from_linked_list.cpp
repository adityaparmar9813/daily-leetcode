class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curr = dummyHead;

        while(curr != nullptr) {
            ListNode* ptr = curr->next;
            int sum = 0;

            while(ptr != nullptr) {
                sum += ptr->val;
                if(sum == 0) {
                    curr->next = ptr->next;
                }
                ptr = ptr->next;
            }
            curr = curr->next;
        }
        return dummyHead->next;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(1)