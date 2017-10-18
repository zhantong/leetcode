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
        if (head == null || head.next == null) {
            return head;
        }
        ListNode back = null;
        ListNode old_head = null;
        while (head != null) {
            old_head = head;
            head = head.next;
            old_head.next = back;
            back = old_head;
        }
        return old_head;
    }
}