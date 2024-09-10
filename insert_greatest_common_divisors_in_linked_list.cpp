class Solution {
  public:
	ListNode *insertGreatestCommonDivisors(ListNode *head) {
		if (head == nullptr) {
			return head;
		}

		ListNode *prev = head;
		ListNode *curr = head->next;

		while (curr != nullptr) {
			prev->next = new ListNode(gcd(prev->val, curr->val), curr);
			prev = curr;
			curr = curr->next;
		}
		return head;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)