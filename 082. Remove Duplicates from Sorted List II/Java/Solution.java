/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode fakeHead = new ListNode(0);
        fakeHead.next = head;
        ListNode node = fakeHead;
        boolean flag = false;
        while (node.next != null && node.next.next != null) {
            if (node.next.val == node.next.next.val) {
                flag = true;
                node.next.next = node.next.next.next;
            } else {
                if (flag) {
                    node.next = node.next.next;
                    flag = false;
                } else {
                    node = node.next;
                }
            }
        }
        if (flag) {
            node.next = node.next.next;
        }
        return fakeHead.next;
    }
}