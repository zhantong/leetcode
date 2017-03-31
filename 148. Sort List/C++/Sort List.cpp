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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode *a = sortList(head);
        ListNode *b = sortList(slow);
        ListNode *fakeHead = new ListNode(0);
        ListNode *temp = fakeHead;
        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                temp->next = a;
                a = a->next;
            } else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        if (a != nullptr) {
            temp->next = a;
        } else {
            temp->next = b;
        }
        return fakeHead->next;
    }
};