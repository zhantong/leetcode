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
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *newHead = head;
        while (head->next != nullptr) {
            ListNode *current = head->next;
            head->next = head->next->next;
            current->next = newHead;
            newHead = current;
        }
        return newHead;
    }
};