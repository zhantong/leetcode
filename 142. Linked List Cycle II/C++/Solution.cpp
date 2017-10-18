/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        unordered_set<ListNode *> visited;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (visited.find(slow) == visited.end()) {
                    visited.insert(slow);
                    slow = slow->next;
                }
                while (visited.find(head) == visited.end()) {
                    head = head->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};