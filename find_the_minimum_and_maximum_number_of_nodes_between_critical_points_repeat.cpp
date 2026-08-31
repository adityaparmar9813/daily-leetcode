class Solution {
   public:
	vector<int> nodesBetweenCriticalPoints(ListNode* head) {
		ListNode* prev = head;
		ListNode* cur = head->next;

		int idx = 1;

		int firstCritical = -1;
		int lastCritical = -1;
		int minDist = INT_MAX;

		while (cur->next) {
			ListNode* next = cur->next;

			bool isMax = cur->val > prev->val && cur->val > next->val;
			bool isMin = cur->val < prev->val && cur->val < next->val;

			if (isMax || isMin) {
				if (lastCritical == -1) {
					firstCritical = idx;
				} else {
					minDist = min(minDist, idx - lastCritical);
				}

				lastCritical = idx;
			}

			prev = cur;
			cur = next;
			idx++;
		}

		if (firstCritical == -1 || firstCritical == lastCritical) {
			return {-1, -1};
		}

		int maxDist = lastCritical - firstCritical;

		return {minDist, maxDist};
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)