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
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *temp = nullptr;
        ListNode *next;
        while (slow) {
            next = slow->next;
            slow->next = temp;
            temp = slow;
            slow = next;
        }
        slow = temp;
        while (head && slow) {
            if (head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};