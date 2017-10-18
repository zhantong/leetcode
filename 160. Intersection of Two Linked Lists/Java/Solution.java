/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lengthA = 0;
        ListNode temp = headA;
        while (temp != null) {
            temp = temp.next;
            lengthA++;
        }
        int lengthB = 0;
        temp = headB;
        while (temp != null) {
            temp = temp.next;
            lengthB++;
        }
        if (lengthA > lengthB) {
            for (int i = 0; i < lengthA - lengthB; i++) {
                headA = headA.next;
            }
        }
        if (lengthB > lengthA) {
            for (int i = 0; i < lengthB - lengthA; i++) {
                headB = headB.next;
            }
        }
        while (headA != headB) {
            headA = headA.next;
            headB = headB.next;
        }
        return headA;
    }
}