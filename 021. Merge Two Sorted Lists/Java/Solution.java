/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        if (l1.val > l2.val) {
            ListNode temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode p = l1;
        while (p != null) {
            while ((l2 != null) && ((p.next == null) || (l2.val < p.next.val))) {
                ListNode temp = l2;
                l2 = l2.next;
                temp.next = p.next;
                p.next = temp;
                p = p.next;
            }
            p = p.next;
        }
        return l1;
    }
}