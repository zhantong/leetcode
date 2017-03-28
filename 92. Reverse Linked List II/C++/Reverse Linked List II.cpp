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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *start = fakeHead;
        n -= m;
        m--;
        while (m) {
            start = start->next;
            m--;
        }
        ListNode *current = start->next;
        while (n) {
            ListNode *temp = start->next;
            start->next = current->next;
            current->next = current->next->next;
            start->next->next = temp;
            n--;
        }
        return fakeHead->next;
    }
};