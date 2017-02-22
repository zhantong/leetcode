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
    ListNode *removeElements(ListNode *head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        ListNode *node = head;
        while (node && node->next) {
            if (node->next->val == val) {
                node->next = node->next->next;
            } else {
                node = node->next;
            }
        }
        return head;
    }
};