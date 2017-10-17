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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *oldHead = nullptr;
        ListNode *back = nullptr;
        while (head != nullptr) {
            oldHead = head;
            head = head->next;
            oldHead->next = back;
            back = oldHead;
        }
        return oldHead;
    }
};