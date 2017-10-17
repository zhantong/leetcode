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
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *middle = slow;
        ListNode *current = middle->next;
        while (current->next != nullptr) {
            ListNode *after = current->next;
            current->next = after->next;
            after->next = middle->next;
            middle->next = after;
        }
        ListNode *p = head;
        while (p != middle) {
            ListNode *temp = middle->next;
            middle->next = temp->next;
            temp->next = p->next;
            p->next = temp;
            p = p->next->next;
        }
    }
};