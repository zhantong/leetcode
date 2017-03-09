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
    ListNode *swapPairs(ListNode *head) {
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *prev = fakeHead;
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode *first = prev->next;
            ListNode *second = first->next;
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
        }
        return fakeHead->next;
    }
};