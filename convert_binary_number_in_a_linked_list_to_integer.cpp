class Solution {
   public:
	int getDecimalValue(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;

		while (curr) {
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		int ans = 0;
		int mul = 1;
		curr = prev;

		while (curr) {
			ans += curr->val * mul;
			mul *= 2;
			curr = curr->next;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)