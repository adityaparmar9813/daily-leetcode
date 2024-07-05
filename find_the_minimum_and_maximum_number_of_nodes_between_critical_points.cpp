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
    bool isCriticalPoint(int prev, ListNode* curr) {
        if (curr->next == nullptr) {
            return false;
        }
        if ((curr->val > prev && curr->val > curr->next->val) || 
            (curr->val < prev && curr->val < curr->next->val)) {
            return true;
        }
        return false;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || head -> next == nullptr || head -> next -> next == nullptr) {
            return {-1, -1};
        }

        int prev = head -> val;
        head = head -> next;

        int index = 1, initialIndex = -1, lastIndex = -1, mini = INT_MAX;
        
        while (head -> next != nullptr) {
            if (isCriticalPoint(prev, head)) {
                if (initialIndex == -1) {
                    initialIndex = index;
                    lastIndex = index;
                } else {
                    mini = min(mini, index - lastIndex);
                    lastIndex = index;
                }
            }
            prev = head->val;
            head = head->next;
            index++;
        }
        
        if (initialIndex == lastIndex) {
            return {-1, -1};
        }

        mini = mini == INT_MAX ? -1 : mini;
        return {mini, lastIndex - initialIndex};
    }
};


// Time Complexity : O(n)
// Space Complexity : O(1)
