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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode *tail = head;
        int length = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }
        if (k % length != 0) {
            tail->next = head;
            int step = length - k % length - 1;
            ListNode *newHead = head;
            for (int i = 0; i < step; i++) {
                newHead = newHead->next;
            }
            head = newHead->next;
            newHead->next = nullptr;
        }
        return head;
    }
};