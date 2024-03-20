class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr1 = list1;
        while(--a) {
            ptr1 = ptr1->next;
            b--;
        }

        ListNode* ptr2 = ptr1;
        while(b > -1) {
            ptr2 = ptr2->next;
            b--;
        }
        
        ptr1->next = list2;
        while(list2->next) {
            list2 = list2->next;
        }
        list2->next = ptr2;
        return list1;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)