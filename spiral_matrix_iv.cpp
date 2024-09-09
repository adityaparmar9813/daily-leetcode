/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
	vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
		int l = 0, r = n - 1, u = 0, d = m - 1, index = 0;
		ListNode *curr = head;
		vector<vector<int>> ans(m, vector<int>(n, -1));

		while (index < m * n) {
			if (curr == nullptr) {
				break;
			}

			switch (index % 4) {
			case 0:
				for (int i = l; i <= r; i++) {
					ans[u][i] = curr->val;
					curr = curr->next;

					if (curr == nullptr) {
						break;
					}
				}
				u++;
				break;
			case 1:
				for (int i = u; i <= d; i++) {
					ans[i][r] = curr->val;
					curr = curr->next;

					if (curr == nullptr) {
						break;
					}
				}
				r--;
				break;
			case 2:
				for (int i = r; i >= l; i--) {
					ans[d][i] = curr->val;
					curr = curr->next;

					if (curr == nullptr) {
						break;
					}
				}
				d--;
				break;
			case 3:
				for (int i = d; i >= u; i--) {
					ans[i][l] = curr->val;
					curr = curr->next;

					if (curr == nullptr) {
						break;
					}
				}
				l++;
				break;
			}
			index++;
		}
		return ans;
	}
};

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)