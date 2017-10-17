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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *fakeHead = new ListNode(0);
        ListNode *temp = fakeHead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int current = carry;
            if (l1 != nullptr) {
                current += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                current += l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode(current % 10);
            temp = temp->next;
            carry = current / 10;
        }
        if (carry != 0) {
            temp->next = new ListNode(carry);
        }
        return fakeHead->next;
    }
};