/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }
        ListNode tail = head;
        int length = 1;
        while (tail.next != null) {
            tail = tail.next;
            length++;
        }
        if (k % length != 0) {
            tail.next = head;
            int step = length - k % length - 1;
            ListNode newHead = head;
            for (int i = 0; i < step; i++) {
                newHead = newHead.next;
            }
            head = newHead.next;
            newHead.next = null;
        }
        return head;
    }
}