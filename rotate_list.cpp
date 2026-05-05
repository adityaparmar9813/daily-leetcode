class Solution {
   public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next || k == 0) {
			return head;
		}

		int len = 1;
		ListNode* curr = head;

		while (curr->next) {
			curr = curr->next;
			len++;
		}

		k %= len;
		if (k == 0) {
			return head;
		}

		curr->next = head;

		ListNode* ptr = head;
		for (int i = 0; i < len - k - 1; i++) {
			ptr = ptr->next;
		}

		ListNode* newHead = ptr->next;
		ptr->next = nullptr;

		return newHead;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)