class Solution {
  public:
	ListNode *modifiedList(vector<int> &nums, ListNode *head) {
		set<int> s;

		for (int num : nums) {
			s.insert(num);
		}

		ListNode *dummyHead = new ListNode(0, head);
		ListNode *curr = dummyHead;

		while (curr->next != nullptr) {
			if (s.count(curr->next->val)) {
				ListNode *toDel = curr->next;
				curr->next = toDel->next;
				delete toDel;
			} else {
				curr = curr->next;
			}
		}
		ListNode *finalHead = dummyHead->next;
		delete dummyHead;
		return finalHead;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)