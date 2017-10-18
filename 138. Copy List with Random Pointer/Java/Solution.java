/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) {
            return head;
        }
        Map<RandomListNode, RandomListNode> memory = new HashMap<>();
        RandomListNode newHead = new RandomListNode(head.label);
        RandomListNode current = head;
        RandomListNode newCurrent = newHead;
        memory.put(current, newCurrent);
        while (current.next != null) {
            newCurrent.next = new RandomListNode(current.next.label);
            memory.put(current.next, newCurrent.next);
            newCurrent = newCurrent.next;
            current = current.next;
        }
        current = head;
        newCurrent = newHead;
        while (current != null) {
            if (current.random != null) {
                newCurrent.random = memory.get(current.random);
            }
            newCurrent = newCurrent.next;
            current = current.next;
        }
        return newHead;
    }
}