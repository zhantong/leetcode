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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *first = head;
        ListNode *second = head;
        ListNode *prev = head;
        while (n) {
            first = first->next;
            n--;
        }
        while (first != nullptr) {
            first = first->next;
            prev = second;
            second = second->next;
        }
        if (second == head) {
            return head->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};