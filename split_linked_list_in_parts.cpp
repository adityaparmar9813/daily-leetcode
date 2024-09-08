class Solution {
  public:
	vector<ListNode *> splitListToParts(ListNode *head, int k) {
		int size = 0;
		ListNode *curr = head;

		while (curr != nullptr) {
			size++;
			curr = curr->next;
		}

		int part = size / k;
		int extra = size % k;

		vector<ListNode *> ans;
		curr = head;

		for (int i = 0; i < k; i++) {
			ListNode *currHead = curr;
			int curr_size = part + (extra-- > 0 ? 1 : 0);

			for (int j = 0; j < curr_size - 1 && curr; j++) {
				curr = curr->next;
			}

			if (curr != nullptr) {
				ListNode *next = curr->next;
				curr->next = nullptr;
				curr = next;
			}
			ans.push_back(currHead);
		}
		return ans;
	}
};

// Time Complexity : O(n + k)
// Space Complexity : O(k)