/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode fakeHead = new ListNode(0);
        ListNode temp = fakeHead;
        int carry = 0;
        while (l1 != null || l2 != null) {
            int current = carry;
            if (l1 != null) {
                current += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                current += l2.val;
                l2 = l2.next;
            }
            temp.next = new ListNode(current % 10);
            temp = temp.next;
            carry = current / 10;
        }
        if (carry != 0) {
            temp.next = new ListNode(carry);
        }
        return fakeHead.next;
    }
}