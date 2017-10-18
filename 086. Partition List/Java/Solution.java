/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode fakeHead = new ListNode(0);
        fakeHead.next = head;
        ListNode greater = fakeHead;
        while (greater.next != null && greater.next.val < x) {
            greater = greater.next;
        }
        ListNode current = greater.next;
        while (current != null && current.next != null) {
            if (current.next.val < x) {
                ListNode temp = greater.next;
                greater.next = current.next;
                current.next = current.next.next;
                greater.next.next = temp;
                greater = greater.next;
            } else {
                current = current.next;
            }
        }
        return fakeHead.next;
    }
}