/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode newHead = head;
        while (head.next != null) {
            ListNode current = head.next;
            head.next = head.next.next;
            current.next = newHead;
            newHead = current;
        }
        return newHead;
    }
}