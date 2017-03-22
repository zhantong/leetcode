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
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *prev = fakeHead;
        ListNode *current = head;
        while (current->next != nullptr) {
            if (current->next->val < current->val) {
                while (prev->next != nullptr && prev->next->val < current->next->val) {
                    prev = prev->next;
                }
                ListNode *temp = prev->next;
                prev->next = current->next;
                current->next = current->next->next;
                prev->next->next = temp;
                prev = fakeHead;
            } else {
                current = current->next;
            }
        }
        return fakeHead->next;
    }
};