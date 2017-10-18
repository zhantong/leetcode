/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return head;
        }
        unordered_map<RandomListNode *, RandomListNode *> memory;
        RandomListNode *newHead = new RandomListNode(head->label);
        RandomListNode *current = head;
        RandomListNode *newCurrent = newHead;
        memory[current] = newCurrent;
        while (current->next != nullptr) {
            newCurrent->next = new RandomListNode(current->next->label);
            memory[current->next] = newCurrent->next;
            newCurrent = newCurrent->next;
            current = current->next;
        }
        current = head;
        newCurrent = newHead;
        while (current != nullptr) {
            if (current->random != nullptr) {
                newCurrent->random = memory[current->random];
            }
            newCurrent = newCurrent->next;
            current = current->next;
        }
        return newHead;
    }
};