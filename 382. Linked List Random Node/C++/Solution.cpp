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
    ListNode *head;

    /** @param head The linked list's head.
    Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *node = head;
        int result = -1;
        int count = 1;
        while (node != nullptr) {
            if (rand() % count == 0) {
                result = node->val;
            }
            count++;
            node = node->next;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */