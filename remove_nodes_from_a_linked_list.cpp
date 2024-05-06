class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;

        while(head != nullptr) {
            while(!st.empty() && head->val > st.top()->val) {
                st.pop();
            }
            st.push(head);
            head = head->next;
        }

        ListNode* curr = nullptr;
        while(!st.empty()) {
            ListNode* top = st.top();
            st.pop();

            top->next = curr;
            curr = top;
        }
        return curr;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
