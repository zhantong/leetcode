/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode first = head;
        ListNode second = head;
        ListNode prev = head;
        while (n != 0) {
            first = first.next;
            n--;
        }
        while (first != null) {
            first = first.next;
            prev = second;
            second = second.next;
        }
        if (second == head) {
            return head.next;
        }
        prev.next = prev.next.next;
        return head;
    }
}