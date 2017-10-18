/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode middle = slow;
        ListNode current = middle.next;
        while (current.next != null) {
            ListNode after = current.next;
            current.next = after.next;
            after.next = middle.next;
            middle.next = after;
        }
        ListNode p = head;
        while (p != middle) {
            ListNode temp = middle.next;
            middle.next = temp.next;
            temp.next = p.next;
            p.next = temp;
            p = p.next.next;
        }
    }
}