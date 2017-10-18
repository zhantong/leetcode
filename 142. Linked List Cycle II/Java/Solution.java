/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode slow = head;
        ListNode fast = head;
        HashSet<ListNode> visited = new HashSet<>();
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                while (!visited.contains(slow)) {
                    visited.add(slow);
                    slow = slow.next;
                }
                while (!visited.contains(head)) {
                    head = head.next;
                }
                return head;
            }
        }
        return null;
    }
}