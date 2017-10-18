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
        class Utils {
            int twoNumbers(ListNode l1, ListNode l2, int length1, int length2, ListNode result) {
                ListNode node = new ListNode(0);
                result.next = node;
                int sumTwo = 0;
                if (l1.next == null) {
                    sumTwo = l1.val + l2.val;
                } else if (length1 > length2) {
                    int carry = twoNumbers(l1.next, l2, length1 - 1, length2, result.next);
                    sumTwo = l1.val + carry;
                } else {
                    int carry = twoNumbers(l1.next, l2.next, length1 - 1, length2 - 1, result.next);
                    sumTwo = l1.val + l2.val + carry;
                }
                node.val = sumTwo % 10;
                return sumTwo / 10;
            }
        }
        int length1 = 0;
        ListNode temp = l1;
        while (temp != null) {
            length1++;
            temp = temp.next;
        }
        int length2 = 0;
        temp = l2;
        while (temp != null) {
            length2++;
            temp = temp.next;
        }
        ListNode result = new ListNode(1);
        Utils utils = new Utils();
        int carry = length1 > length2 ? utils.twoNumbers(l1, l2, length1, length2, result) : utils.twoNumbers(l2, l1, length2, length1, result);
        if (carry == 0) {
            result = result.next;
        }
        return result;
    }
}