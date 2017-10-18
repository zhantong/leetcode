/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode fakeHead = new ListNode(0);
        fakeHead.next = head;
        ListNode tail = fakeHead;
        ListNode current = fakeHead;
        while (true) {
            int count = k;
            while (count != 0 && tail != null) {
                tail = tail.next;
                count--;
            }
            if (tail == null) {
                break;
            }
            ListNode tempHead = current.next;
            while (current.next != tail) {
                ListNode node = current.next;
                current.next = node.next;
                node.next = tail.next;
                tail.next = node;
            }
            current = tempHead;
            tail = tempHead;
        }
        return fakeHead.next;
    }
}